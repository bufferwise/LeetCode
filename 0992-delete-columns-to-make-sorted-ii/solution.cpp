#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        int deletions = 0;
        
        vector<bool> isSorted(n - 1, false);
        
        for (int j = 0; j < m; j++) {
            int i;
            
            for (i = 0; i < n - 1; i++) {
                if (!isSorted[i] && strs[i][j] > strs[i+1][j]) {
                    deletions++;
                    break;
                }
            }
            
            if (i == n - 1) {
                for (int k = 0; k < n - 1; k++) {
                    if (strs[k][j] < strs[k+1][j]) {
                        isSorted[k] = true;
                    }
                }
            }
        }
        
        return deletions;
    }
};

