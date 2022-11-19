class Solution {
public:
    vector<vector<int>>dp;
    int n,m;
    int paths(vector<vector<int>>grid,int i,int j){
        if(i>=n || j>=m || grid[i][j]==1){
            return 0;
        }
        // vis[i][j]=1;
        if(i==n-1 && j==m-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=paths(grid,i+1,j)+paths(grid,i,j+1);
        return dp[i][j]=ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        n=grid.size();
        m=grid[0].size();
        dp=vector<vector<int>>(n,vector<int>(m,-1));
        return paths(grid,0,0);
    }
};