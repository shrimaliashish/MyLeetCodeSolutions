class Solution {
public:
    int mx=2*10001;
    int fun(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n=grid.size(),m=grid[0].size();
        if(i>=n || j>=m)
            return mx;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==n-1 && j==m-1)
            return grid[i][j];
        int right=fun(i,j+1,grid,dp);
        int down=fun(i+1,j,grid,dp);
        return dp[i][j]=(right!=mx || down!=mx)? grid[i][j]+min(right,down):mx;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fun(0,0,grid,dp);
    }
};