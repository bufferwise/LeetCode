class Solution 
{
    public int minimumBoxes(int[] apple, int[] capacity) 
    {
        int total = 0 ;
        int cnt = 0 ;

        for(int i=0 ; i<apple.length ; i++)
        {
            total =total + apple[i] ;
        }

        Arrays.sort(capacity) ;

        for(int i=capacity.length-1 ; i>=0  ; i--)
        {
            if(total == 0) break ; 
            if(capacity[i] <= total && total >0)
            {
                cnt++;
                total= total - capacity[i] ;
            }
            else
            {
                cnt++ ;
                total = 0 ;
            }
        }   
        return cnt ;
    }
}
