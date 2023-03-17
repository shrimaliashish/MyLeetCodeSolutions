class Solution {
public:
    int fees;
    int fun(int i,int buy,vector<int>&p, vector<vector<int>>&dp){
        if(i==p.size()){
            return 0;
        }
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-p[i]+fun(i+1,0,p,dp),fun(i+1,1,p,dp));
        }else{
            profit=max(+p[i]-fees+fun(i+1,1,p,dp),fun(i+1,0,p,dp));
        }
        return  dp[i][buy]= profit;
    }
    
    
    int maxProfit(vector<int>& p, int fee) {
        fees=fee;
       vector<vector<int>>dp(p.size(),vector<int>(2,-1));
        return fun(0,1,p,dp);
    }
};