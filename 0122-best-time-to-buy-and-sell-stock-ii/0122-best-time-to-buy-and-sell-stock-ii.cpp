class Solution {
public:
    vector<vector<int>>dp;
    int fun(int i,int buy,vector<int>&p){
        if(i==p.size()){
            return 0;
        }
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(-p[i]+fun(i+1,0,p),fun(i+1,1,p));
        }else{
            profit=max(+p[i]+fun(i+1,1,p),fun(i+1,0,p));
        }
        return  dp[i][buy]= profit;
    }
    
    // int fun(vector<int>p,)
    
    int maxProfit(vector<int>& p) {
        dp=vector<vector<int>>(p.size(),vector<int>(2,-1));
        return fun(0,1,p);
        
    }
};