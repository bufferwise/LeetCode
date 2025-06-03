import java.util.*;

class Solution {
    
    /**
     * Finds maximum candies using optimized BFS approach.
     * Time: O(n), Space: O(n) - each box processed at most once
     * 
     * @param status Box open/closed status
     * @param candies Candies in each box
     * @param keys Keys obtained from each box
     * @param containedBoxes Boxes found inside each box
     * @param initialBoxes Initially available boxes
     * @return Maximum candies obtainable
     */
    public int maxCandies(int[] status, int[] candies, int[][] keys, 
                         int[][] containedBoxes, int[] initialBoxes) {
        
        int n = status.length;
        int totalCandies = 0;
        
        // Bit arrays for O(1) lookups - more memory efficient than HashSet
        boolean[] hasBox = new boolean[n];      // Boxes we possess
        boolean[] hasKey = new boolean[n];      // Keys we possess
        boolean[] processed = new boolean[n];   // Already processed boxes
        
        // Queue for BFS - only open boxes we can process
        ArrayDeque<Integer> queue = new ArrayDeque<>();
        
        // Initialize with starting boxes
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box] == 1) { // Box is open
                queue.offer(box);
            }
        }
        
        // BFS to process all accessible boxes
        while (!queue.isEmpty()) {
            int box = queue.poll();
            
            if (processed[box]) continue;
            processed[box] = true;
            
            // Collect candies from current box
            totalCandies += candies[box];
            
            // Collect keys from current box
            for (int key : keys[box]) {
                if (!hasKey[key]) {
                    hasKey[key] = true;
                    // If we have the box and just got the key, we can open it
                    if (hasBox[key] && !processed[key]) {
                        queue.offer(key);
                    }
                }
            }
            
            // Collect contained boxes
            for (int containedBox : containedBoxes[box]) {
                if (!hasBox[containedBox]) {
                    hasBox[containedBox] = true;
                    // If box is open or we have key, we can process it
                    if ((status[containedBox] == 1 || hasKey[containedBox]) 
                        && !processed[containedBox]) {
                        queue.offer(containedBox);
                    }
                }
            }
        }
        
        return totalCandies;
    }
    
    /**
     * Test cases to verify correctness
     */
    public static void main(String[] args) {
        Solution sol = new Solution();
        
        // Test 1
        int[] status1 = {1,0,1,0};
        int[] candies1 = {7,5,4,9};
        int[][] keys1 = {{},{},{1},{}};
        int[][] containedBoxes1 = {{1,2},{3},{},{}};
        int[] initialBoxes1 = {0};
        System.out.println(sol.maxCandies(status1, candies1, keys1, containedBoxes1, initialBoxes1)); // 16
        
        // Test 2  
        int[] status2 = {1,0,0,0,0,0};
        int[] candies2 = {1,1,1,1,1,1};
        int[][] keys2 = {{1,2,3,4,5},{},{},{},{},{}};
        int[][] containedBoxes2 = {{},{},{},{},{},{}};
        int[] initialBoxes2 = {0};
        System.out.println(sol.maxCandies(status2, candies2, keys2, containedBoxes2, initialBoxes2)); // 6
    }
}
