class Solution {
public:
    vector<vector<int>>dp;
    int fun(int ind,vector<int>& a,int segment,int k){
        if(segment==0)
            return 0;
        if(ind>=a.size())
            return 0;
        if(dp[ind][segment]!=-1)
            return dp[ind][segment];
        int non_pick=fun(ind+1,a,segment,k);
        int mx_reach=lower_bound(a.begin(),a.end(),a[ind]+k+1)-a.begin();
        int pick=mx_reach-ind;
        pick+=fun(mx_reach,a,segment-1,k);
        return dp[ind][segment]=max(pick,non_pick);
    }
    int maximizeWin(vector<int>& a, int k) {
        dp.resize(a.size(),vector<int>(3,-1));
        return fun(0,a,2,k);
    }
};