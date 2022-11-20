class Solution {
public:
    int fun(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>&dp){
        int n=triangle.size(),m=triangle[i].size();
        if(j>=m)
            return INT_MAX;
        if(i==n-1)
            return triangle[i][j];
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j]=min(triangle[i][j]+fun(i+1,j,triangle,dp),triangle[i][j]+fun(i+1,j+1,triangle,dp));        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size(),m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(0,0,triangle,dp);
    }
};