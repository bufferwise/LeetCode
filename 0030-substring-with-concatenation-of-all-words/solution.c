/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Simple structure for a Hash Map entry
typedef struct {
    char* word;
    int count;
} WordCount;

// Helper to find word index in the map (Manual Hash/Search)
int findWord(WordCount* map, int size, char* target) {
    for (int i = 0; i < size; i++) {
        if (strcmp(map[i].word, target) == 0) return i;
    }
    return -1;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int sLen = strlen(s);
    int wordLen = strlen(words[0]);
    int totalWordsLen = wordsSize * wordLen;
    *returnSize = 0;

    if (sLen < totalWordsLen) return NULL;

    int* result = malloc(sizeof(int) * sLen);
    
    // 1. Create a frequency map of the 'words' array
    WordCount* baseMap = malloc(sizeof(WordCount) * wordsSize);
    int uniqueWords = 0;
    for (int i = 0; i < wordsSize; i++) {
        int idx = findWord(baseMap, uniqueWords, words[i]);
        if (idx != -1) {
            baseMap[idx].count++;
        } else {
            baseMap[uniqueWords].word = words[i];
            baseMap[uniqueWords].count = 1;
            uniqueWords++;
        }
    }

    // 2. Sliding Window: Run for each possible starting offset [0, wordLen - 1]
    for (int i = 0; i < wordLen; i++) {
        int left = i, right = i, count = 0;
        int* currCount = calloc(uniqueWords, sizeof(int));

        while (right + wordLen <= sLen) {
            char temp = s[right + wordLen];
            s[right + wordLen] = '\0'; // Temporary null terminator for strcmp
            char* sub = &s[right];
            
            int idx = findWord(baseMap, uniqueWords, sub);
            s[right + wordLen] = temp; // Restore

            if (idx != -1) {
                currCount[idx]++;
                count++;
                
                // If we have too many of this word, shrink from the left
                while (currCount[idx] > baseMap[idx].count) {
                    char tempL = s[left + wordLen];
                    s[left + wordLen] = '\0';
                    int leftIdx = findWord(baseMap, uniqueWords, &s[left]);
                    s[left + wordLen] = tempL;
                    
                    currCount[leftIdx]--;
                    count--;
                    left += wordLen;
                }
                
                // If the window size matches our target, we found a match
                if (count == wordsSize) {
                    result[(*returnSize)++] = left;
                }
            } else {
                // Invalid word: reset window
                memset(currCount, 0, sizeof(int) * uniqueWords);
                count = 0;
                left = right + wordLen;
            }
            right += wordLen;
        }
        free(currCount);
    }

    free(baseMap);
    return result;
}
