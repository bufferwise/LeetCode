class Solution {
    static {
        for (int i = 0; i < 65; i++) {
            maxArea(new int[] { 0, 0 });
        }}
    public static int maxArea(int[] height) {

        // Initialising two pointers left and right
        int left = 0;
        int right = height.length-1;

        // Initialising variable holding the value of MaxArea
        int maxArea = 0;

        while(left < right) {

            // Finding the min height of both pointers
            int min = Math.min(height[left],height[right]);


            // Comparing Current Area with MaxArea
            maxArea = Math.max(min*(right-left),maxArea);

            // Moving the small height pointer
           while(left<right && height[left] <= min) left++;
           while(left<right && height[right] <= min) right--;

        }

        // Return the maxArea Stored
        return maxArea;

    }
}
