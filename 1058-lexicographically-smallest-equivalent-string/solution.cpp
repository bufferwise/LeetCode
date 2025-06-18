class Solution {
public:
    int find(int node, vector<int>&parent)
    {
        if(node != parent[node])
        {
            parent[node] = find(parent[node], parent);
        }
        return parent[node];
    }
    string smallestEquivalentString(string s1, string s2, string word) {
        vector<int>parent(26);
        for(int i=0;i<26;i++)parent[i] =i;
        for(int i=0;i<s1.size();i++)
        {
            int u = find(s1[i]-'a', parent);
            int v = find(s2[i]-'a', parent);
            if(u!=v) parent[max(u, v)] = min(u, v);

        }
        string res ="";
        for(char ch:word)
        {
            res+=char(find(ch-'a', parent)+ 'a');
        }
        return res;

    }
       
};
