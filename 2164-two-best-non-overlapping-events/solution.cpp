#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int start, end, val;
};

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = events.size();

        vector<Event> evs(n);
        for (int i = 0; i < n; ++i) {
            evs[i] = {events[i][0], events[i][1], events[i][2]};
        }

        sort(evs.begin(), evs.end(), [](const Event& a, const Event& b) {
            return a.start < b.start;
        });

        vector<int> suffixMax(n + 1, 0);
        suffixMax[n - 1] = evs[n - 1].val;
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(evs[i].val, suffixMax[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {

            int currentVal = evs[i].val;

            int target = evs[i].end;
            int left = i + 1, right = n - 1;
            int nextBestIdx = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (evs[mid].start > target) {
                    nextBestIdx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            if (nextBestIdx != -1) {
                currentVal += suffixMax[nextBestIdx];
            }
            
            if (currentVal > ans) ans = currentVal;
        }

        return ans;
    }
};
