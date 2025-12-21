#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();
        long total = 0;
        for (int count : machines) total += count;

        if (total % n != 0) return -1;

        int target = total / n;
        int maxMoves = 0;
        int balance = 0;

        for (int count : machines) {

            int diff = count - target;

            balance += diff;

            maxMoves = max({maxMoves, abs(balance), diff});
        }

        return maxMoves;
    }
};

