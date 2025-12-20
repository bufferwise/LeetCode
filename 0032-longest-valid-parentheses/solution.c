int longestValidParentheses(char* s) {
    int n = 0;
    while (s[n] != '\0') n++;
    
    int left = 0, right = 0, max_len = 0;

    // First pass: Left to Right
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            int current_len = 2 * right;
            if (current_len > max_len) max_len = current_len;
        } else if (right > left) {
            left = right = 0;
        }
    }

    left = right = 0;

    // Second pass: Right to Left
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            left++;
        } else {
            right++;
        }
        
        if (left == right) {
            int current_len = 2 * left;
            if (current_len > max_len) max_len = current_len;
        } else if (left > right) {
            left = right = 0;
        }
    }

    return max_len;
}
