#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    int* eventA = *(int**)a;
    int* eventB = *(int**)b;
    return eventA[0] - eventB[0];
}

int maxTwoEvents(int** events, int eventsSize, int* eventsColSize) {

    qsort(events, eventsSize, sizeof(int*), compare);

    int* suffixMax = (int*)malloc(sizeof(int) * eventsSize);
    suffixMax[eventsSize - 1] = events[eventsSize - 1][2];
    for (int i = eventsSize - 2; i >= 0; i--) {
        suffixMax[i] = (events[i][2] > suffixMax[i + 1]) ? events[i][2] : suffixMax[i + 1];
    }

    int maxSum = 0;

    for (int i = 0; i < eventsSize; i++) {
        if (events[i][2] > maxSum) maxSum = events[i][2];
        int target = events[i][1] + 1;
        int left = i + 1, right = eventsSize - 1;
        int bestFutureIdx = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] >= target) {
                bestFutureIdx = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (bestFutureIdx != -1) {
            int currentSum = events[i][2] + suffixMax[bestFutureIdx];
            if (currentSum > maxSum) maxSum = currentSum;
        }
    }

    free(suffixMax);
    return maxSum;
}
