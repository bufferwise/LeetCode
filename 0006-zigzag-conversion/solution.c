/* 2025/05/31 - Coded on (2025/05/29)
 * 0-3ms runtime, O(n) time, O(n) space.
 *
 * The Algorithm:
 *   1) Handle the base case, if the number of rows is one, return the input string.
 *   2) Get and store the length of the input string.
 *   3) Allocate space for a new string of equal length.
 *   4) Find the amount of characters in one zigzag. (One less than the number of rows, doubled.)
 *   5) Iterate through zero up to but not including the number of rows:
 *     a) Create a variable to 
 */
char* convert(char* s, int numRows) {
    if(numRows == 1) return s;
    int firstOffset = (numRows - 1) << 1;
    int len = strlen(s);
    char* rtnStr = malloc(sizeof(char) * (len + 1));
    int index = 0;
    for(int i = 0; i < numRows; ++i) {
        for(int rowIndex = 0; rowIndex < len; rowIndex += firstOffset) {
            int bottomRow = rowIndex + i;
            int topRow = rowIndex + (firstOffset - i);
            if(bottomRow >= len) continue;
            rtnStr[index++] = s[bottomRow];
            if(i == 0 || bottomRow == topRow || topRow >= len) continue;
            rtnStr[index++] = s[topRow];
        }
    }
    rtnStr[len] = 0;
    return rtnStr;
}
