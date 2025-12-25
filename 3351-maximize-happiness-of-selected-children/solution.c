#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

long long maximumHappinessSum(int* happiness, int happinessSize, int k) {
    qsort(happiness, happinessSize, sizeof(int), compare);
    
    long long total = 0;
    for (int i = 0; i < k; i++) {
        int current = happiness[i] - i;
        
        if (current <= 0) break;
        
        total += current;
    }
    
    return total;
}
