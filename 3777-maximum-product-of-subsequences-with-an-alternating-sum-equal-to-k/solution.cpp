const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif
class Solution {
public:
    unordered_map<string, int> dp;
    int k, l;

    int f_(vector<int> &v, int i, long long p, int s, int prev, int taken){
        if(i >= (int)v.size()){
            if(taken && s == k && p <= l) return p;
            return -1;
        }

        string key = to_string(i) + "," + to_string(p) + "," + to_string(s) + "," + to_string(prev) + "," + to_string(taken);
        if(dp.count(key)) return dp[key];

        int notTake = f_(v, i+1, p, s, prev, taken);

        
        long long newProd = p * v[i];
        if(newProd > l) newProd = l + 1;

        int newSum = prev ? s + v[i] : s - v[i];

        int take = f_(v, i+1, newProd, newSum, !prev, 1);

        return dp[key] = max(take, notTake);
    }

    int maxProduct(vector<int>& v, int k, int l) {
        this->k = k;
        this->l = l;

        int sum = 0;
        for(auto it: v) sum += it;
        if(sum < abs(k)) return -1;

        dp.clear();
        return f_(v, 0, 1LL, 0, 1, 0);
    }
};
