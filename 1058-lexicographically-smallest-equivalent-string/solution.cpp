#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        iota(parent.begin(), parent.end(), 0);
        
        function<int(int)> find = [&](int x) {
            return parent[x] == x ? x : parent[x] = find(parent[x]);
        };
        
        for (int i = 0; i < s1.size(); ++i) {
            int a = find(s1[i] - 'a'), b = find(s2[i] - 'a');
            if (a != b) parent[max(a, b)] = min(a, b);
        }
        
        string result;
        result.reserve(baseStr.size());
        for (char c : baseStr) {
            result += char('a' + find(c - 'a'));
        }
        
        return result;
    }
};

static const auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
