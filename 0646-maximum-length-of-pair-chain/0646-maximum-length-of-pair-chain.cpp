class Solution {
public:
    static bool cmp(const vector<int>a,const vector<int>b ){
        return a[1]<b[1];
    }
    int solve(int i,int prev,vector<vector<int>>& pairs,vector<vector<int>>&dp){
        int n=pairs.size();
        if(i==n)
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int take=0;
        if(prev==-1 || pairs[i][0]>pairs[prev][1]){
            take=1+solve(i+1,i,pairs,dp);
        }
        int notTake=solve(i+1,prev,pairs,dp);
        return dp[i][prev+1]= max(take,notTake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int n=pairs.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,pairs,dp);
    }
};