import java.util.*;

class Solution {
    public int maxTwoEvents(int[][] events) {
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        int n = events.length;
        int[] suffixMax = new int[n];
        suffixMax[n - 1] = events[n - 1][2];
        
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = Math.max(events[i][2], suffixMax[i + 1]);
        }
        
        int maxSum = 0;
        for (int i = 0; i < n; i++) {
            int currentVal = events[i][2];
            int left = i + 1, right = n - 1, nextIdx = -1;
            
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[i][1]) {
                    nextIdx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            if (nextIdx != -1) currentVal += suffixMax[nextIdx];
            maxSum = Math.max(maxSum, currentVal);
        }
        return maxSum;
    }
}
