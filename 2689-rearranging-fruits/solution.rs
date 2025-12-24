use std::collections::HashMap;

impl Solution {
    pub fn min_cost(basket1: Vec<i32>, basket2: Vec<i32>) -> i64 {
        let mut map: HashMap<i32, i32> = HashMap::new();
        let mut min_val = i32::MAX;
        for &x in &basket1 {
            *map.entry(x).or_insert(0) += 1;
            min_val = min_val.min(x);
        }
        for &x in &basket2 {
            *map.entry(x).or_insert(0) -= 1;
            min_val = min_val.min(x);
        }

        let mut to_swap = Vec::new();
        for (&val, &diff) in map.iter() {
            if diff % 2 != 0 { 
                return -1; 
            }
            let count = diff.abs() / 2;
            for _ in 0..count {
                to_swap.push(val);
            }
        }

        to_swap.sort_unstable();
        
        let mut res = 0i64;
        let n = to_swap.len() / 2;
        
        for i in 0..n {
            res += (to_swap[i].min(2 * min_val)) as i64;
        }
        
        res
    }
}
