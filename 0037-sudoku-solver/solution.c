#include <stdbool.h>

int rows[9];
int cols[9];
int boxes[9];

// Helper to get the box index (0-8)
inline int getBox(int r, int c) {
    return (r / 3) * 3 + (c / 3);
}

bool backtrack(char** board, int n) {
    if (n == 81) return true; // Board full

    int r = n / 9;
    int c = n % 9;

    if (board[r][c] != '.') {
        return backtrack(board, n + 1);
    }

    int boxIdx = getBox(r, c);
    // Combine masks: find bits that are 0 in all three sets
    int used = rows[r] | cols[c] | boxes[boxIdx];

    for (int num = 1; num <= 9; num++) {
        int mask = 1 << num;
        if (!(used & mask)) {
            // Set bit
            board[r][c] = num + '0';
            rows[r] |= mask;
            cols[c] |= mask;
            boxes[boxIdx] |= mask;

            if (backtrack(board, n + 1)) return true;

            // Reset bit (Backtrack)
            board[r][c] = '.';
            rows[r] &= ~mask;
            cols[c] &= ~mask;
            boxes[boxIdx] &= ~mask;
        }
    }
    return false;
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    // Reset bitmasks for new test cases
    for (int i = 0; i < 9; i++) {
        rows[i] = cols[i] = boxes[i] = 0;
    }

    // Pre-fill bitmasks with existing numbers
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] != '.') {
                int mask = 1 << (board[r][c] - '0');
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[getBox(r, c)] |= mask;
            }
        }
    }

    backtrack(board, 0);
}
