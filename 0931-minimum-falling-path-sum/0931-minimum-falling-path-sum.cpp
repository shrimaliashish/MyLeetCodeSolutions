
class Solution {
public:

    
    int falling(int i,int j,vector<vector<int>>& mat,vector<vector<int>>& dp){
        int n=mat.size();
        int m=mat[0].size();
        if(j<0 || j>=m){
            return INT_MAX;
        }
        if(i==n-1)
            return mat[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        return dp[i][j]=mat[i][j]+ min({
                falling(i+1,j-1,mat,dp),
                falling(i+1,j,mat,dp),
                falling(i+1,j+1,mat,dp)
            });
       
    }   
    int minFallingPathSum(vector<vector<int>>& mat) {
        vector<vector<int>>dp( 101 , vector<int> (101 , INT_MAX));
        int mn=INT_MAX;
        for(int i=0;i<mat[0].size();i++){
            mn=min(mn,falling(0,i,mat,dp));
        }
        return mn;
    }
};