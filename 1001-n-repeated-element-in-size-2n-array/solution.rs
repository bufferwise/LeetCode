impl Solution {
    pub fn repeated_n_times(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        
        for distance in 1..=3 {
            for i in 0..(n - distance) {
                if nums[i] == nums[i + distance] {
                    return nums[i];
                }
            }
        }
        -1
    }
}
