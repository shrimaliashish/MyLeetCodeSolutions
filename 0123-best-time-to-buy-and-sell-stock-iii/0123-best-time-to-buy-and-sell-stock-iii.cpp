class Solution {
public:
    int fun(int i,int buy,int cap,vector<int>&p, vector<vector<vector<int>>>&dp){
        if(i==p.size() || cap==0){
            return 0;
        }
        if(dp[i][buy][cap]!=-1)
            return dp[i][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-p[i]+fun(i+1,0,cap,p,dp),fun(i+1,1,cap,p,dp));
        }else{
            profit=max(+p[i]+fun(i+1,1,cap-1,p,dp),fun(i+1,0,cap,p,dp));
        }
        return  dp[i][buy][cap]= profit;
    }
    int maxProfit(vector<int>& p) {
        int n=p.size();
        vector<vector<vector<int>>>dp(p.size(),vector<vector<int>>(2,vector<int>(3 , -1)));
        return fun(0,1,2,p,dp);
    }
};