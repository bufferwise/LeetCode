#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_ptr = 0, p_ptr = 0;
        int s_star = -1, p_star = -1;
        int s_len = s.length();
        int p_len = p.length();

        while (s_ptr < s_len) {
            
            if (p_ptr < p_len && (p[p_ptr] == '?' || p[p_ptr] == s[s_ptr])) {
                s_ptr++;
                p_ptr++;
            }
            
            else if (p_ptr < p_len && p[p_ptr] == '*') {
                p_star = p_ptr;
                s_star = s_ptr;
                p_ptr++; // Move pattern pointer, but keep s_ptr same (matching 0 chars)
            }
            
            else if (p_star != -1) {
                p_ptr = p_star + 1; // Backtrack to the pattern after '*'
                s_star++;           // The '*' now matches one more character in s
                s_ptr = s_star;     // Reset s_ptr to the new starting point
            }
            
            else {
                return false;
            }
        }

        
        while (p_ptr < p_len && p[p_ptr] == '*') {
            p_ptr++;
        }

        return p_ptr == p_len;
    }
};
