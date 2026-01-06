use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;

impl Solution {
    pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let root = match root {
            Some(node) => node,
            None => return 0,
        };

        let mut max_sum = i32::MIN;
        let mut max_level = 1;
        let mut current_level = 1;
        
        let mut queue = VecDeque::new();
        queue.push_back(root);

        while !queue.is_empty() {
            let level_size = queue.len();
            let mut level_sum = 0;

            for _ in 0..level_size {
                if let Some(node) = queue.pop_front() {
                    let node_borrow = node.borrow();
                    level_sum += node_borrow.val;

                    if let Some(left) = node_borrow.left.clone() {
                        queue.push_back(left);
                    }
                    if let Some(right) = node_borrow.right.clone() {
                        queue.push_back(right);
                    }
                }
            }
            
            if level_sum > max_sum {
                max_sum = level_sum;
                max_level = current_level;
            }

            current_level += 1;
        }

        max_level
    }
}
