const int MIN = -5000;

class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int, int>>>> dp;
    int recursion(int pos, int currSum, int product, int isOdd, int k, int n, vector<int> &nums, int limit) {
        if(pos == n) {
            return (currSum == k && isOdd != 0 && product <= limit ? product : MIN);
        }
        
        if(dp.count(pos) && dp[pos].count(currSum) && dp[pos][currSum].count(product) && dp[pos][currSum][product].count(isOdd)) {
            return dp[pos][currSum][product][isOdd];
        }
            
        int ans = recursion(pos + 1, currSum, product, isOdd, k, n, nums, limit);
        if(isOdd == 0) {
            ans = max(ans, recursion(pos + 1, currSum + nums[pos], nums[pos], 2, k, n, nums, limit));
        }
        if(isOdd == 1) {
            ans = max(ans, recursion(pos + 1, currSum + nums[pos], min(product * nums[pos], limit + 1), 2, k, n, nums, limit));
        }
        if(isOdd == 2) {
            ans = max(ans, recursion(pos + 1, currSum - nums[pos], min(product * nums[pos], limit + 1), 1, k, n, nums, limit));
        }
        
        return dp[pos][currSum][product][isOdd] = ans;
    }
    
    int maxProduct(vector<int> &nums, int k, int limit) {
        int n = nums.size();
        
        int sum = 0;
        for(auto &x: nums) sum += x;
        
        if(k > sum || k < -sum) return -1;
            
        dp.clear();
        int ans = recursion(0, 0, 0, 0, k, n, nums, limit);
        return (ans == MIN) ? -1 : ans;
    }
};
