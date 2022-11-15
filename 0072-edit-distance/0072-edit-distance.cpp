class Solution {
public:
    vector<vector<int>>dp;
    int f(int i,int j,string str1,string str2){
        if(i<0)
            return j+1;
        if(j<0)
            return i+1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(str1[i]==str2[j]){
            return dp[i][j]=f(i-1,j-1,str1,str2);
        }else{
            int del=1+f(i-1,j,str1,str2);
            int replace=1+f(i-1,j-1,str1,str2);
            int insert=1+f(i,j-1,str1,str2);
            return dp[i][j]=min({del,insert,replace});
        }
        return 0;
    }
    int minDistance(string word1, string word2) {
        dp=vector<vector<int>>(word1.size(),vector<int>(word2.size(),-1));
        return f(word1.size()-1,word2.size()-1,word1,word2);
    }
};