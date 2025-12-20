#include <string.h>

int minDeletionSize(char** strs, int strsSize) {
    if (strsSize <= 1) {
        return 0;
    }

    int deleteCount = 0;
    int colLength = strlen(strs[0]);

    // Iterate through each column
    for (int j = 0; j < colLength; j++) {
        // Check rows in the current column
        for (int i = 0; i < strsSize - 1; i++) {
            // If the current character is greater than the next, it's not sorted
            if (strs[i][j] > strs[i+1][j]) {
                deleteCount++;
                break; // No need to check the rest of this column
            }
        }
    }

    return deleteCount;
}
