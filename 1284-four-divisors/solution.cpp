#include <vector>
#include <cmath>

using namespace std;

static const int fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;
        
        for (int n : nums) {
            int count = 0;
            int currentSum = 0;
            int last_d = 0;
            
            for (int d = 2; d * d <= n; ++d) {
                if (n % d == 0) {
                    if (d * d == n) {

                        count = 5;
                    } else {
                        count += 2;
                        currentSum += d + (n / d);
                        last_d = d;
                    }
                }
                if (count > 2) break;
            }
            
            if (count == 2) {
                totalSum += (1 + n + currentSum);
            }
        }
        
        return totalSum;
    }
};
