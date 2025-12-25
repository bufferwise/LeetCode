import java.util.Arrays;

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {

        Arrays.sort(happiness);
        
        long total = 0;
        int n = happiness.length;

        for (int i = 0; i < k; i++) {

            int current = happiness[n - 1 - i] - i;

            if (current <= 0) break;
            
            total += current;
        }
        
        return total;
    }
}
