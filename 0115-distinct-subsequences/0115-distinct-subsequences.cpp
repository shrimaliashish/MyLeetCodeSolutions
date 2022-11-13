class Solution {
public:
    int m,n;
    string str1="",str2="";
    vector<vector<int>>dp;
    int f(int i,int j){
        if(j<0)
        return 1;
        if(i<0)
        return 0;
        if(dp[i][j]!=-1)
        return dp[i][j];
        if(str1[i]==str2[j]){
            dp[i][j]=f(i-1,j)+f(i-1,j-1);
        }else{
            dp[i][j]=f(i-1,j);
        }
        return dp[i][j];
    }

    int numDistinct(string s, string t) {
        str1=s,str2=t;
        // cout<<str1<<endl<<str2<<endl;
        n=s.size();
        m=t.size();
        dp=vector<vector<int>>(n,vector<int>(m,-1));
        
        return f(n-1,m-1);
    }
};