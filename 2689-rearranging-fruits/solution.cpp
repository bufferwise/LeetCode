#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    long long minCost(std::vector<int>& basket1, std::vector<int>& basket2) {
        std::map<int, int> count;
        int min_val = INT_MAX;
        for (int x : basket1) { count[x]++; min_val = std::min(min_val, x); }
        for (int x : basket2) { count[x]--; min_val = std::min(min_val, x); }

        std::vector<int> swap_list;
        for (auto const& [val, freq] : count) {
            if (freq % 2 != 0) return -1;
            for (int i = 0; i < std::abs(freq) / 2; ++i) {
                swap_list.push_back(val);
            }
        }

        std::sort(swap_list.begin(), swap_list.end());
        long long total_cost = 0;
        
        for (int i = 0; i < swap_list.size() / 2; ++i) {
            total_cost += std::min(swap_list[i], 2 * min_val);
        }
        return total_cost;
    }
};
