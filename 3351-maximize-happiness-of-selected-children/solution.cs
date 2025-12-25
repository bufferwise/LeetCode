using System;

public class Solution {
    public long MaximumHappinessSum(int[] happiness, int k) {
        Array.Sort(happiness);
        
        long total = 0;
        int n = happiness.Length;
        
        for (int i = 0; i < k; i++) {
            int currentVal = happiness[n - 1 - i] - i;
            if (currentVal <= 0) break;
            
            total += (long)currentVal;
        }
        
        return total;
    }
}
