class Solution {
    public static String convert(String arr, int rows) {
        int std = 2*rows - 2;
        int len = arr.length();
        char[] ans = new char[len];
        int point = 0;
        if(rows == 1 || rows > len) return arr;
        for(int i = 0 ; i < rows ; i++) {
            int j = i;
            ans[point++] = arr.charAt(j);
            while(true)
            {
                int k = j;
                if(j + 2*(rows-i-1) >= len) break;
                if(i != rows-1)
                {
                    j = j + 2*(rows-i-1);
                    ans[point++] = arr.charAt(j);
                }
                if(j + 2*i >= len) break;
                if(i!=0)
                {
                    j = j + 2*(i);
                    ans[point++] = arr.charAt(j);
                }
                if(k == j)
                {
                    break;
                }
            }
        }

        String answer = new String(ans);
        return answer;
    }
}
