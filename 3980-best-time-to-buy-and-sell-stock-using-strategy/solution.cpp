#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long baseProfit = 0;
        
        
        for (int i = 0; i < n; ++i) {
            baseProfit += (long long)strategy[i] * prices[i];
        }

        
        long long currentGain = 0;
        int halfK = k / 2;
        
        
        for (int i = 0; i < halfK; ++i) {
            currentGain -= (long long)strategy[i] * prices[i];
        }
        
        for (int i = halfK; i < k; ++i) {
            currentGain += (long long)(1 - strategy[i]) * prices[i];
        }

        long long maxGain = max(0LL, currentGain);

        
        for (int i = 1; i <= n - k; ++i) {
            
            currentGain += (long long)strategy[i - 1] * prices[i - 1];
            
            
            currentGain -= prices[i + halfK - 1];
            
            
            currentGain += (long long)(1 - strategy[i + k - 1]) * prices[i + k - 1];

            if (currentGain > maxGain) maxGain = currentGain;
        }

        return baseProfit + maxGain;
    }
};
