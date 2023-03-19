class Solution {
public:
    int solve(int i,int j,string &str1,string &str2,vector<vector<int>>&dp){
        if(i<0 || j<0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take=0;
        if(str1[i]==str2[j]){
            take=2*str1[i]+solve(i-1,j-1,str1,str2,dp);
        }
        int notTake=max(solve(i-1,j,str1,str2,dp),solve(i,j-1,str1,str2,dp));
        return dp[i][j]= max(take,notTake);
        
            
    }
    int minimumDeleteSum(string s1, string s2) {
        int mx=0;
        for(auto x:s1)
            mx+=int(x);
        for(auto x:s2)
            mx+=int(x);
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        int k=solve(n1-1,n2-1,s1,s2,dp);
            return mx-k;
    }
};