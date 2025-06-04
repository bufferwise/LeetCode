class Solution {
    public String answerString(String word, int numFriends) {
        if (numFriends == 1) return word;
        
        int n = word.length();
        int maxLen = n - numFriends + 1;
        String result = "";
        
        for (int i = 0; i < n; i++) {
            int len = Math.min(maxLen, n - i);
            String candidate = word.substring(i, i + len);
            if (candidate.compareTo(result) > 0) {
                result = candidate;
            }
        }
        
        return result;
    }
}
