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
            //that unknown part started which I was talking about
            vector<int>dp(n+1,0);
            // ith position of this vector defines that till ith position it can be made from some word from the list
            dp[0]=1;
            for(int i=0;i<n;i++){
                if(!dp[i]) continue;
                
                for(int j=i+1;j<=n;j++){
                    if(j-i<n && st.count(word.substr(i,j-i))){
                        dp[j]=1;
                    }
                }
                // adding word to the list if that satisfies our condition
                if(dp[n]){
                    res.push_back(word);
                    break;
                }
            }
            //that unknown part started which I was talking about
        }
        return res;
    }
};