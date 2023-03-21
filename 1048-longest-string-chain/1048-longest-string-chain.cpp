class Solution {
public:
    bool checkpossible(string s1 ,string s2){
        if(s1.size() != s2.size() + 1) return false;
        int first = 0;
        int second = 0;
        while(first < s1.size()){
            if( second < s2.size() && s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }

        if(first == s1.size() && second == s2.size()) return true;
        else return false;
    }
     static bool cmp(string s1 ,string s2){
        return s1.size() < s2.size();
    }
    int solve(int i,int prev,vector<string>&a,vector<vector<int>>&dp){
        if(i==a.size())
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int notTake=solve(i+1,prev,a,dp);
        int take=0;
        if(prev==-1 || checkpossible(a[i],a[prev]))
            take=1+solve(i+1,i,a,dp);
        return dp[i][prev+1]= max(take,notTake);
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        // for(int i=1;i<words.size();i++)
        //     cout<<words[i-1]<<" "<<words[i]<<" "<<check(words[i-1],words[i])<<endl;
        // vector<vector<int>>dp(words.size(),vector<int>(words.size()+1,-1));
        // return solve(0,-1,words,dp);
        int ans=1;
        vector<int>dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            int prev=0;
            for(int j=0;j<i;j++){
                if(checkpossible(words[i],words[j])){
                    prev=max(dp[j],prev);
                }
            }
            dp[i]=1+prev;
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
