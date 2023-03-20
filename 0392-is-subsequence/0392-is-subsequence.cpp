class Solution {
public:
    bool check(int i,int j,string &s,string &t,vector<vector<int>>&dp){
        if(i==s.size())
            return true;
        if(j==t.size())
            return false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool res=false;
        if(s[i]==t[j])
            res=check(i+1,j+1,s,t,dp);
        else{
            res=check(i,j+1,s,t,dp) || res;
        }
        return dp[i][j]= res;
    }
    
    bool isSubsequence(string s, string t) {
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        return check(0,0,s,t,dp);
    }
};