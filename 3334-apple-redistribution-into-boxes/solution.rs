impl Solution {
    pub fn minimum_boxes(apple: Vec<i32>, mut capacity: Vec<i32>) -> i32 {
        let mut total_apples: i32 = apple.iter().sum();

        capacity.sort_unstable_by(|a, b| b.cmp(a));
        
        let mut count = 0;
        for cap in capacity {
            if total_apples <= 0 {
                break;
            }
            total_apples -= cap;
            count += 1;
        }
        count
    }
}
