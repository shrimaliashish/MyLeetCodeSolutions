class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int sum,vector<int>& coins){
        if(sum==0)
            return 0;
        if(i<0){
            return 1e9;
        }
       if(dp[i][sum]!=-1)
           return dp[i][sum];
        int take=1e9;
        if(coins[i]<=sum){
            take=min(1+solve(i-1,sum-coins[i],coins),1+solve(i,sum-coins[i],coins));
        }
        int notTake=solve(i-1,sum,coins);
        return dp[i][sum]= min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp=vector<vector<int>>(n,vector<int>(amount+1,-1));
        int ans=solve(n-1,amount,coins);
        return ans==1e9?-1:ans;
    }
};