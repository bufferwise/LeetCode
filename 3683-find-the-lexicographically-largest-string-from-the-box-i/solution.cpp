class Solution 
{
public:
    string answerString(string word, int numFriends) 
    {
        // Step 1: Edge case
        if (numFriends == 1) 
	{
		return word;
	}

        int n = word.size();
    
        // Step 2: Compute max part length
        int maxLen = n - numFriends + 1;
        string res = "";

        // Step 3: Iterate over all valid substrings
        for (int i = 0; i < n; ++i) 
        {
            int len = min(n - i, maxLen);
            string substr = word.substr(i, len);

            // Step 4: Compare and update result
            if (substr > res) 
            {
                res = substr;
            }
        }

        // Step 5: Return the result
        return res;
    }
};
