class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;
        
        StringBuilder[] rows = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            rows[i] = new StringBuilder();
        }
        
        int row = 0;
        boolean down = false;
        
        for (char c : s.toCharArray()) {
            rows[row].append(c);
            
            if (row == 0 || row == numRows - 1) {
                down = !down;
            }
            
            row += down ? 1 : -1;
        }
        
        StringBuilder result = new StringBuilder();
        for (StringBuilder sb : rows) {
            result.append(sb);
        }
        
        return result.toString();
    }
}
