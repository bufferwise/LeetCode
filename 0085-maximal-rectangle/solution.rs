impl Solution {
    pub fn maximal_rectangle(matrix: Vec<Vec<char>>) -> i32 {
        if matrix.is_empty() { return 0; }
        let cols = matrix[0].len();
        let mut heights = vec![0; cols];
        let mut max_area = 0;

        for row in matrix {
            for j in 0..cols {
                heights[j] = if row[j] == '1' { heights[j] + 1 } else { 0 };
            }
            max_area = max_area.max(Self::largest_rectangle_in_histogram(&heights));
        }
        max_area
    }

    fn largest_rectangle_in_histogram(heights: &[i32]) -> i32 {
        let mut stack = Vec::new();
        let mut max_a = 0;
        let n = heights.len();

        for i in 0..=n {
            let h = if i == n { 0 } else { heights[i] };
            while let Some(&top_idx) = stack.last() {
                if heights[top_idx] >= h {
                    let height = heights[stack.pop().unwrap()];
                    let width = if stack.is_empty() { i as i32 } else { (i - stack.last().unwrap() - 1) as i32 };
                    max_a = max_a.max(height * width);
                } else {
                    break;
                }
            }
            stack.push(i);
        }
        max_a
    }
}
