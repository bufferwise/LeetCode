import java.util.HashMap;

class Solution {
    
    /**
     * Finds indices of two numbers that add up to target.
     * Time Complexity: O(n) - single pass through array
     * Space Complexity: O(n) - HashMap storage
     * 
     * @param nums Array of integers
     * @param target Target sum
     * @return Array containing indices of the two numbers
     */
    public static int[] twoSum(int[] nums, int target) {
        // Use HashMap for O(1) lookups - initial capacity optimized for expected size
        HashMap<Integer, Integer> map = new HashMap<>(nums.length);
        
        // Single pass: check if complement exists, then add current number
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            
            // Check if complement exists in map
            if (map.containsKey(complement)) {
                return new int[]{map.get(complement), i};
            }
            
            // Store current number and its index
            map.put(nums[i], i);
        }
        
        // Should never reach here given problem constraints
        return new int[0];
    }
    
    /**
     * Test method to verify solution
     */
    public static void main(String[] args) {
        // Test case 1: [2,7,11,15], target = 9
        int[] nums1 = {2, 7, 11, 15};
        int[] result1 = twoSum(nums1, 9);
        System.out.println("Result: [" + result1[0] + ", " + result1[1] + "]"); // [0, 1]
        
        // Test case 2: [3,2,4], target = 6
        int[] nums2 = {3, 2, 4};
        int[] result2 = twoSum(nums2, 6);
        System.out.println("Result: [" + result2[0] + ", " + result2[1] + "]"); // [1, 2]
        
        // Test case 3: [3,3], target = 6
        int[] nums3 = {3, 3};
        int[] result3 = twoSum(nums3, 6);
        System.out.println("Result: [" + result3[0] + ", " + result3[1] + "]"); // [0, 1]
    }
}
