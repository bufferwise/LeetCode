#include <vector>
#include <stack>
#include <algorithm>

class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int cols = matrix[0].size();
        std::vector<int> heights(cols, 0);
        int maxArea = 0;

        for (const auto& row : matrix) {
            for (int j = 0; j < cols; ++j) {
                heights[j] = (row[j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = std::max(maxArea, calculateHistogram(heights));
        }
        return maxArea;
    }

private:
    int calculateHistogram(std::vector<int>& heights) {
        std::stack<int> s;
        heights.push_back(0); // Sentinel
        int max_a = 0;
        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] >= heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int w = s.empty() ? i : i - s.top() - 1;
                max_a = std::max(max_a, h * w);
            }
            s.push(i);
        }
        heights.pop_back();
        return max_a;
    }
};
