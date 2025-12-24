#include <stdlib.h>
#include <stdint.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

long long minCost(int* basket1, int n, int* basket2, int n2) {
    qsort(basket1, n, sizeof(int), cmp);
    qsort(basket2, n, sizeof(int), cmp);
    
    int g_min = basket1[0] < basket2[0] ? basket1[0] : basket2[0];
    int *diffs = malloc(sizeof(int) * 2 * n);
    int d_idx = 0;
    
    int i = 0, j = 0;
    while (i < n || j < n) {
        int val = (i < n && (j == n || basket1[i] < basket2[j])) ? basket1[i] : basket2[j];
        int c1 = 0, c2 = 0;
        while (i < n && basket1[i] == val) { c1++; i++; }
        while (j < n && basket2[j] == val) { c2++; j++; }
        
        if ((c1 + c2) % 2 != 0) { free(diffs); return -1; }
        int extra = (c1 > c2) ? (c1 - c2) / 2 : (c2 - c1) / 2;
        for (int k = 0; k < extra; k++) diffs[d_idx++] = val;
    }
    
    qsort(diffs, d_idx, sizeof(int), cmp);
    long long total = 0;
    for (int k = 0; k < d_idx / 2; k++) {
        long long bridge = 2LL * g_min;
        total += (diffs[k] < bridge) ? diffs[k] : bridge;
    }
    
    free(diffs);
    return total;
}
