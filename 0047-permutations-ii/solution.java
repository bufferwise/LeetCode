class Solution {
    HashSet <List<Integer>> set = new HashSet<>();
    public List<List<Integer>> permuteUnique(int[] nums) {
        boolean used[] = new boolean[nums.length];
        permute(new ArrayList<Integer>(),nums, used);
        return new ArrayList(set);
    }
    
    public void permute(List<Integer> permutation, int []nums,  boolean used[]){
                
        if(permutation.size() == nums.length){
            set.add(new ArrayList<Integer>(permutation));
            return;
        }

        for(int i = 0; i < nums.length; i++){
            if(!used[i]){
                permutation.add(nums[i]);
                used[i] = true;
                permute(permutation, nums, used);
                permutation.remove(permutation.size()-1);
                used[i] =false;
            }

        }
        
    }
}
