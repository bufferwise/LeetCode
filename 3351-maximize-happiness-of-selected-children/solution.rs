impl Solution {
    pub fn maximum_happiness_sum(mut happiness: Vec<i32>, k: i32) -> i64 {

        happiness.sort_unstable_by(|a, b| b.cmp(a));
        
        let mut total: i64 = 0;
        let k = k as usize;

        for i in 0..k {

            let val = happiness[i] as i64 - i as i64;

            if val <= 0 {
                break;
            }
            
            total += val;
        }
        
        total
    }
}
