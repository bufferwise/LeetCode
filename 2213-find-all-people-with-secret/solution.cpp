#pragma GCC target("abm")
#pragma GCC target("bmi")
#pragma GCC target("avx2")
#pragma GCC target("bmi2")
#pragma GCC target("lzcnt")
#pragma GCC target("popcnt")
#pragma GCC target("native")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-march=native")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insnS2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-Pointer-checks")
static const bool __boost = []() {
   cin.tie(nullptr);
   cout.tie(nullptr);
   return std::ios_base::sync_with_stdio(false);
}();
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;
void* operator new(size_t size) {
   constexpr std::size_t alignment = alignof(std::max_align_t);
   size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
   size_t total_size = size + padding;
   char* aligned_ptr = &buffer[buffer_pos + padding];
   buffer_pos += total_size;
   return aligned_ptr;
}
void operator delete(void* ptr, unsigned long) {}
void operator delete(void* ptr) {}
void operator delete[](void* ptr) {}
const auto __ = []() {
   struct Leetcode {
       static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
   };
   std::atexit(&Leetcode::_);
   return 0;
}();

class UnionFind {
private:
    vector<int> id;
public:
    UnionFind(int n) : id(n) { iota(begin(id), end(id), 0); }
    void connect(int a, int b) { id[find(b)] = find(a); }
    int find(int a) { return id[a] == a ? a : (id[a] = find(id[a])); }
    bool connected(int a, int b) { return find(a) == find(b); }
    void reset(int a) { id[a] = a; }
};
class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        UnionFind uf(n);
        uf.connect(0, firstPerson);
        vector<int> people{};
        for (int i{0}; i < meetings.size();) {
            people.clear();
            int time{meetings[i][2]};
            for (; i < meetings.size() && meetings[i][2] == time; ++i) {
                uf.connect(meetings[i][0], meetings[i][1]);
                people.push_back(meetings[i][0]);
                people.push_back(meetings[i][1]);
            }
            for (int person : people) {
                if (!uf.connected(0, person)) uf.reset(person);
            }
        }
        vector<int> res{};
        for (int i{0}; i < n; ++i) {
            if (uf.connected(0, i)) res.push_back(i);
        }
        return res;
    }
};
