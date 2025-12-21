#include <vector>
#include <algorithm>

using namespace std;

class SnapshotArray {
private:
    // history[index] stores a vector of {snap_id, value}
    vector<vector<pair<int, int>>> history;
    int current_snap_id;

public:
    SnapshotArray(int length) {
        history.resize(length);
        for (int i = 0; i < length; i++) {
            // Initial state: at snap_id 0, the value is 0
            history[i].push_back({0, 0});
        }
        current_snap_id = 0;
    }
    
    void set(int index, int val) {
        // If the last entry in this index's history is the same snap_id,
        // just update the value instead of adding a new pair.
        if (!history[index].empty() && history[index].back().first == current_snap_id) {
            history[index].back().second = val;
        } else {
            history[index].push_back({current_snap_id, val});
        }
    }
    
    int snap() {
        return current_snap_id++;
    }
    
    int get(int index, int snap_id) {
        // We need the value at snap_id. We search for the first element
        // with a snap_id GREATER than the one requested.
        auto it = upper_bound(history[index].begin(), history[index].end(), make_pair(snap_id, numeric_limits<int>::max()));
        
        // The element before that is the latest version available at snap_id.
        return prev(it)->second;
    }
};
