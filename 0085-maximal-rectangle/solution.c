int largestRectangleArea(int* heights, int n) {
    int stack[n + 1];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int h = (i == n) ? 0 : heights[i];

        while (top != -1 && h < heights[stack[top]]) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            int area = height * width;
            if (area > maxArea)
                maxArea = area;
        }
        stack[++top] = i;
    }
    return maxArea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0)
        return 0;

    int cols = matrixColSize[0];
    int heights[cols];
    for (int i = 0; i < cols; i++)
        heights[i] = 0;

    int maxArea = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }

        int area = largestRectangleArea(heights, cols);
        if (area > maxArea)
            maxArea = area;
    }

    return maxArea;
}
