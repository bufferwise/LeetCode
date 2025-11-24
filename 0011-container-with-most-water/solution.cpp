class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int maxVol = INT_MIN;

        while(l < r) {
            maxVol = max(maxVol, (r - l) * min(height[l], height[r]));
            // We can do THREE things here
            // 1st:
            // if (height[l] >= height[r]) r--;
            // else l++;
            // 2nd:
            // if (height[l] < height[r]) l++;
            // else r--;
            // 3rd:
            if (height[l] <= height[r]) l++;
            else r--;
        }

        return maxVol;




        // int maxArea = 0;
        // int left = 0;
        // int right = height.size() - 1;

        // while (left < right) {
        //     maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
        //     if (height[left] < height[right]) {
        //         left++;
        //     } 
        //     else {
        //         right--;
        //     }
        // }
        // return maxArea;        
    }
};
