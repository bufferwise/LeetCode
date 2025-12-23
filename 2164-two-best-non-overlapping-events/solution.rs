impl Solution {
    pub fn max_two_events(mut events: Vec<Vec<i32>>) -> i32 {
        events.sort_unstable_by_key(|e| e[0]);
        let n = events.len();
        let mut suffix_max = vec![0; n];
        suffix_max[n - 1] = events[n - 1][2];
        
        for i in (0..n - 1).rev() {
            suffix_max[i] = suffix_max[i + 1].max(events[i][2]);
        }
        
        let mut max_sum = 0;
        for i in 0..n {
            let mut current_val = events[i][2];
            let end_time = events[i][1];
            
            // Binary search for the first event starting after events[i] ends
            let mut low = i + 1;
            let mut high = n;
            while low < high {
                let mid = low + (high - low) / 2;
                if events[mid][0] > end_time {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            
            if low < n {
                current_val += suffix_max[low];
            }
            max_sum = max_sum.max(current_val);
        }
        max_sum
    }
}
