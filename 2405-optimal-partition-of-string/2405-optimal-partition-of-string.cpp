class Solution {
public:
    
    int partitionString(string s) {
        int n=s.size();
        vector<int>dp(n+1,1);
        unordered_map<char,int>m;
        for(int i=1;i<=n;i++){
            if(m.count(s[i-1])==0){
                 m[s[i-1]]=1;
                dp[i]=dp[i-1];
            }else{
                m.clear();
                m[s[i-1]]=1;
                dp[i]=dp[i-1]+1;
            }
        }
        return dp[n];
    }
};