function maximalRectangle(matrix: string[][]): number {
    if (matrix.length === 0) return 0;
    const cols = matrix[0].length;
    const heights = new Array(cols).fill(0);
    let maxArea = 0;

    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < cols; j++) {
            heights[j] = matrix[i][j] === '1' ? heights[j] + 1 : 0;
        }
        maxArea = Math.max(maxArea, largestInHistogram(heights));
    }
    return maxArea;
}

function largestInHistogram(heights: number[]): number {
    const stack: number[] = [];
    let maxA = 0;
    for (let i = 0; i <= heights.length; i++) {
        const h = i === heights.length ? 0 : heights[i];
        while (stack.length > 0 && heights[stack[stack.length - 1]] >= h) {
            const height = heights[stack.pop()!];
            const width = stack.length === 0 ? i : i - stack[stack.length - 1] - 1;
            maxA = Math.max(maxA, height * width);
        }
        stack.push(i);
    }
    return maxA;
}
