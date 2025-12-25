#include <vector>
#include <algorithm>

static const int fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    long long maximumHappinessSum(std::vector<int>& happiness, int k) {
        std::nth_element(happiness.begin(), happiness.begin() + k, happiness.end(), std::greater<int>());
        std::sort(happiness.begin(), happiness.begin() + k, std::greater<int>());

        long long totalHappiness = 0;
        for (int i = 0; i < k; ++i) {
            int currentHappiness = happiness[i] - i;
            if (currentHappiness <= 0) break;
            
            totalHappiness += currentHappiness;
        }
        
        return totalHappiness;
    }
};
