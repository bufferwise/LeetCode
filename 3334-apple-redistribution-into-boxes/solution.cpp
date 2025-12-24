#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    int minimumBoxes(std::vector<int>& apple, std::vector<int>& capacity) {
        int totalApples = std::accumulate(apple.begin(), apple.end(), 0);

        std::sort(capacity.begin(), capacity.end(), std::greater<int>());
        
        int boxes = 0;
        for (int cap : capacity) {
            totalApples -= cap;
            boxes++;
            if (totalApples <= 0) break;
        }
        return boxes;
    }
};
