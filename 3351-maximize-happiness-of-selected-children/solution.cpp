class Solution {
public:
    long long maximumHappinessSum(vector<int>& a, int k) {
        long long res = 0, i;
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        for (i = 0; i < k; ++i) res += max(0LL, a[i] - i);
        return res;
    }
};
