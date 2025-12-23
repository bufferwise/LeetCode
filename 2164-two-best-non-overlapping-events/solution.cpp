class Solution {
    private:
    int n;
    int findUpperBound(vector<vector<int>>& ev, int k){

        int l = -1, r= n;

        while(r-l>1){
            int mid = l+(r-l)/2;
            if(ev[mid][0]>k) r= mid;
            else l = mid;
        }

        return r;
    }
public:
    

    int maxTwoEvents(vector<vector<int>>& ev) {

        n = ev.size();

        sort(ev.begin(),ev.end());

        int maxi = 0;

        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,ev[i][2]);
            ev[i].push_back(maxi);
        }

        maxi = 0;

        for(int i=0;i<n;i++){
            int e = ev[i][1];
            int cv = ev[i][2];

            int ub = findUpperBound(ev,e);

            if(ub!=n) cv+=ev[ub][3];

            maxi = max(maxi, cv);


        }

        return maxi;
        
    }
};
