import java.util.*;

class Solution {
    public int maxCandies(int[] status, int[] candies, int[][] keys, int[][] containedBoxes, int[] initialBoxes) {
        int n = status.length;
        boolean[] hasBox = new boolean[n];
        boolean[] hasKey = new boolean[n];
        boolean[] visited = new boolean[n];
        
        // Mark initial boxes as owned
        for (int box : initialBoxes) {
            hasBox[box] = true;
        }
        
        int totalCandies = 0;
        boolean changed = true;
        
        while (changed) {
            changed = false;
            
            for (int i = 0; i < n; i++) {
                // Can open if: have box AND (box is open OR have key) AND not visited
                if (hasBox[i] && (status[i] == 1 || hasKey[i]) && !visited[i]) {
                    visited[i] = true;
                    changed = true;
                    totalCandies += candies[i];
                    
                    // Get keys from this box
                    for (int key : keys[i]) {
                        hasKey[key] = true;
                    }
                    
                    // Get contained boxes
                    for (int box : containedBoxes[i]) {
                        hasBox[box] = true;
                    }
                }
            }
        }
        
        return totalCandies;
    }
}
