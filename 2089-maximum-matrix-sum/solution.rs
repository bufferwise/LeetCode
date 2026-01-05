impl Solution {
    pub fn max_matrix_sum(matrix: Vec<Vec<i32>>) -> i64 {
        let mut total_sum: i64 = 0;
        let mut min_abs = i32::MAX;
        let mut negative_count = 0;

        for row in matrix.iter() {
            for &val in row.iter() {
                let abs_val = val.abs();
                if val < 0 {
                    negative_count += 1;
                }
                if abs_val < min_abs {
                    min_abs = abs_val;
                }
                total_sum += abs_val as i64;
            }
        }

        if negative_count % 2 == 0 {
            total_sum
        } else {
            // Subtract twice the minimum absolute value 
            // (once to remove it from the total_sum, once to account for its negative state)
            total_sum - 2 * (min_abs as i64)
        }
    }
}
