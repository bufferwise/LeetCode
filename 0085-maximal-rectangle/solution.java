import java.util.Stack;

class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0) return 0;
        int[] heights = new int[matrix[0].length];
        int maxArea = 0;

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }
            maxArea = Math.max(maxArea, largestInHistogram(heights));
        }
        return maxArea;
    }

    private int largestInHistogram(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int maxA = 0;
        for (int i = 0; i <= heights.length; i++) {
            int h = (i == heights.length) ? 0 : heights[i];
            while (!stack.isEmpty() && heights[stack.peek()] >= h) {
                int height = heights[stack.pop()];
                int width = stack.isEmpty() ? i : i - stack.peek() - 1;
                maxA = Math.max(maxA, height * width);
            }
            stack.push(i);
        }
        return maxA;
    }
}
