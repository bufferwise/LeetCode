#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        
        sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        
        vector<bool> knows(n, false);
        knows[0] = true;
        knows[firstPerson] = true;

        int m = meetings.size();
        
        vector<pair<int, int>> adj[n]; 
        
        
        int i = 0;
        while (i < m) {
            int currentTime = meetings[i][2];
            int j = i;
            
            static vector<int> peopleAtTime;
            peopleAtTime.clear();
            
            
            while (j < m && meetings[j][2] == currentTime) {
                int u = meetings[j][0];
                int v = meetings[j][1];
                
                
                if (adj[u].empty()) peopleAtTime.push_back(u);
                if (adj[v].empty()) peopleAtTime.push_back(v);
                
                adj[u].push_back({v, currentTime});
                adj[v].push_back({u, currentTime});
                j++;
            }

            queue<int> q;
            for (int p : peopleAtTime) {
                if (knows[p]) {
                    q.push(p);
                }
            }

            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                
                for (auto& edge : adj[curr]) {
                    int neighbor = edge.first;
                    if (!knows[neighbor]) {
                        knows[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }


            for (int p : peopleAtTime) {
                adj[p].clear();
            }
            
            i = j;
        }

        vector<int> result;
        for (int k = 0; k < n; k++) {
            if (knows[k]) result.push_back(k);
        }
        return result;
    }
};
