#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    int find(vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent, parent[i]);
    }

    
    void unite(vector<int>& parent, int i, int j) {
        int root_i = find(parent, i);
        int root_j = find(parent, j);
        if (root_i != root_j) parent[root_i] = root_j;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        
        unite(parent, 0, firstPerson);

        int m = meetings.size();
        int i = 0;
        while (i < m) {
            int currentTime = meetings[i][2];
            int j = i;
            
            
            vector<int> pool;
            while (j < m && meetings[j][2] == currentTime) {
                int u = meetings[j][0];
                int v = meetings[j][1];
                unite(parent, u, v);
                pool.push_back(u);
                pool.push_back(v);
                j++;
            }

            
            int root0 = find(parent, 0);
            for (int p : pool) {
                if (find(parent, p) != root0) {
                    parent[p] = p;
                }
            }
            i = j;
        }

        vector<int> result;
        int root0 = find(parent, 0);
        for (int k = 0; k < n; k++) {
            if (find(parent, k) == root0) {
                result.push_back(k);
            }
        }
        return result;
    }
};
