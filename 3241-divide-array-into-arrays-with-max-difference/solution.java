class Solution {
    public int[][] divideArray(int[] nums, int k) {
        int max = Integer.MIN_VALUE;
        for(int i: nums)
            max = Math.max(i, max);
        int[] count = new int[max+1];
        for(int i:nums)
            count[i]++;
        int[][] res = new int[nums.length/3][3];
        int row=0, col=0;
        for(int i=0;i<max+1;i++){
            if(count[i]>0){
                while(count[i]>0){
                    res[row][col++] = i;
                    if(col==3){
                        if(Math.abs(res[row][0]-res[row][2])>k) return new int[0][0];
                        row++;col=0;
                    }
                    count[i]--;
                }
            }
        }  
        return res;
    }
}
