class Solution {
public:
    int fun(int i,int j,int sum,int k,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        int n=grid.size(),m=grid[0].size();
        int mod=1e9+7;
        if(i>=n || j>=m)
            return 0;
        if(i==n-1 && j==m-1){
            sum=(sum+grid[i][j])%k;
           return sum%k==0;
        }
        if(dp[i][j][sum]!=-1)
            return dp[i][j][sum];
        int cur=(sum%k+grid[i][j]%k)%k;
        int right=fun(i,j+1,cur,k,grid,dp);
        int down=fun(i+1,j,cur,k,grid,dp);
        return dp[i][j][sum]=(right%mod+down%mod)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int mod=1e9+7;
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return  fun(0,0,0,k,grid,dp);
    }
};