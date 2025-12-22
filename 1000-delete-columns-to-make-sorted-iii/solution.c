#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int minDeletionSize(char** strs, int strsSize) {
    int colLen = strlen(strs[0]);

    int dp[101]; 
    int maxKept = 1;

    for (int i = 0; i < colLen; i++) {
        dp[i] = 1;
    }

    for (int i = 1; i < colLen; i++) {
        for (int j = 0; j < i; j++) {
            int valid = 1;
            for (int k = 0; k < strsSize; k++) {
                if (strs[k][j] > strs[k][i]) {
                    valid = 0;
                    break;
                }
            }
            
            if (valid) {
                dp[i] = MAX(dp[i], dp[j] + 1);
            }
        }
        maxKept = MAX(maxKept, dp[i]);
    }
    return colLen - maxKept;
}
