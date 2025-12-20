#include <stdbool.h>

bool isValid(char** board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {

        // Row check
        if (board[row][i] == c) return false;

        // Column check
        if (board[i][col] == c) return false;

        // 3×3 subgrid check
        int subRow = 3 * (row / 3) + i / 3;
        int subCol = 3 * (col / 3) + i % 3;
        if (board[subRow][subCol] == c) return false;
    }
    return true;
}

bool solve(char** board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {

            if (board[row][col] == '.') {

                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, row, col, c)) {
                        board[row][col] = c;

                        if (solve(board)) return true;

                        board[row][col] = '.';  // undo move
                    }
                }
                return false; // no valid number found
            }
        }
    }
    return true; // solved!
}

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}

