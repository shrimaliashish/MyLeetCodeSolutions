class Solution {
public:
    vector<vector<int>>dp;
    int path(int i,int j,int n,int m){
        if(i>=n || j>=m)
            return 0;
        if(i==n-1 && j==m-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=path(i,j+1,n,m)+path(i+1,j,n,m);     
    }
    int uniquePaths(int m, int n) {
        dp=vector<vector<int>>(101,vector<int>(101,-1));
         return path(0,0,n,m);
    }
};