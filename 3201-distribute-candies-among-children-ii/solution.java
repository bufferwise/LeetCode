class Solution {
    
public long distributeCandies(int n, int limit) {
    return F(n) 
           - 3 * F(n - (long) limit - 1) 
           + 3 * F(n - 2L * limit - 2) 
           - F(n - 3L * limit - 3);
}

private long F(long m) {
    if (m < 0) {
        return 0;
    }
    return (m + 2) * (m + 1) / 2;
}
    }
