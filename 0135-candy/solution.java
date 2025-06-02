public class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        if (n <= 1) return n;
        
        int up = 0, down = 0, peak = 0, total = 1;
        
        for (int i = 1; i < n; i++) {
            if (ratings[i - 1] < ratings[i]) {
                up++;
                down = 0;
                peak = up;
                total += 1 + up;
            } else if (ratings[i - 1] > ratings[i]) {
                up = 0;
                down++;
                total += 1 + down - (peak >= down ? 1 : 0);
            } else {
                up = down = peak = 0;
                total++;
            }
        }
        
        return total;
    }
}
