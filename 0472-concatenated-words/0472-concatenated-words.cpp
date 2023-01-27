class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string>st;
        for(auto x:words){
            st.insert(x);
        }
        vector<string>res;
        for(auto word:words){
            int n=word.length();
            vector<int>dp(n+1,0);
            dp[0]=1;

            for(int i=0;i<n;i++){
                if(!dp[i]) continue;
                
                for(int j=i+1;j<=n;j++){
                    if(j-i<n && st.count(word.substr(i,j-i))){
                        dp[j]=1;
                    }
                }
                if(dp[n]){
                    res.push_back(word);
                    break;
                }
            }
        }
        return res;
    }
};