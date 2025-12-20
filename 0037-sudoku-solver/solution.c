
void solveSudoku(char **board, int boardSize, int *boardColSize) {
  bool rowHash[9][10] = {false}, colHash[9][10] = {false}, blockHash[3][3][10] = {false}; // hash tables
  int rowFilledCnt[9] = {0}, colFilledCnt[9] = {0}, blockFilledCnt[3][3] = {0};           // non-empty cell count
  char path[81][3];                                                                       // searching path, (path[i] = {row, col, val})
  int maxLen = 0;                                                                         // max legth of `path`(initial empty cell count)

  // 0. initialize helpers
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      int val = board[i][j] == '.' ? 0 : board[i][j] - '0';
      if (val) {
        rowHash[i][val] = true, colHash[j][val] = true, blockHash[i / 3][j / 3][val] = true;
        rowFilledCnt[i]++, colFilledCnt[j]++, blockFilledCnt[i / 3][j / 3]++;
      } else
        memcpy(path[maxLen++], (char[]){i, j, 0}, 3);
    }
  }

  // 1. find optimal searching path
  for (int curr = 0; curr < maxLen; curr++) {
    // find the ideal cell with maximum sum of cnts in pathlist following `path[curr]`(included)
    int maxCnt = -1, maxIdx = curr;
    for (int k = curr; k < maxLen; k++) {
      int i = path[k][0], j = path[k][1];
      int currCnt = rowFilledCnt[i] + colFilledCnt[j] + blockFilledCnt[i / 3][j / 3];
      if (currCnt > maxCnt)
        maxCnt = currCnt, maxIdx = k;
    }
    // push ideal cell to front by swapping `path[curr]` and `path[maxIdx]`
    int i = path[maxIdx][0], j = path[maxIdx][1];
    memcpy(path[maxIdx], path[curr], 2);
    memcpy(path[curr], (char[]){i, j}, 2);
    // propagate by updating cnts
    rowFilledCnt[i]++, colFilledCnt[j]++, blockFilledCnt[i / 3][j / 3]++;
  }

  // 2. search for result, guided by path
  for (int curr = 0; curr < maxLen;) {
    int i = path[curr][0], j = path[curr][1], val = path[curr][2];
    // discard current cell, propagate this change to hash tables
    rowHash[i][val] = false, colHash[j][val] = false, blockHash[i / 3][j / 3][val] = false;
    // try to find a valid value for current position
    for (int n = val + 1; n < 10; n++) {
      if (rowHash[i][n] || colHash[j][n] || blockHash[i / 3][j / 3][n])
        continue;
      else {
        val = n;
        break;
      }
    }
    // check if valid value is found
    if (val == path[curr][2]) { // not found, backtrack
      path[curr][2] = 0;
      curr--;
    } else { // found, iterate forward
      path[curr][2] = val, rowHash[i][val] = true, colHash[j][val] = true, blockHash[i / 3][j / 3][val] = true;
      curr++;
    }
  }

  // 3. final: fill results back to grid
  for (int i = 0; i < maxLen; i++)
    board[path[i][0]][path[i][1]] = '0' + path[i][2];
}
