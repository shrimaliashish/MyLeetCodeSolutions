class Solution {
public:
    int fun(int i,int j,int n,vector<vector<int>>&dp){
        if(i==n)
            return 0;
        if(i>n)
            return 10000;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int copy=10000,paste=10000;
        if(j<i)
        copy=1+fun(i,i,n,dp);
        if(j!=0)
        paste=1+fun(i+j,j,n,dp);
        return dp[i][j]= min(copy,paste);
    }
    // int getMinimum(int i,int j,int n,vector<vector<int>>&dp){
    //     if(i==n)
    //     return 0;
    //   if(i>n)
    //     return 10000;
    //     if(dp[i][j]!=-1)
    //        return dp[i][j];
    //   if(i==j)
    //     return 1+getMinimum(i+j,j,n,dp);
    //   if(n==1)
    //     return 0;
    //   if(j==0)
    //   return 1+getMinimum(i,i,n,dp);
    //   else
    //   return dp[i][j]= min(1+getMinimum(i,i,n,dp),1+getMinimum(i+j,j,n,dp));
    // }
    int minSteps(int n) {
        vector<vector<int>>dp(n+1,vector<int>(2*n+1,-1));
        return fun(1,0,n,dp);
    }
};