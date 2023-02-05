class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len=s.size(),p_len=p.size();
        vector<int>p_freq(26,0);
        vector<int>window(26,0);
        vector<int>ans;
        if(p_len>s_len)
            return ans;
        for(auto x:p){
            p_freq[x-'a']++;
        }
        for(int i=0;i<p_len;i++){
           window[s[i]-'a']++;
        }
        // for(auto x:window)
        //     cout<<x<<" ";
        // cout<<endl;
        // for(auto x:p_freq)
        //     cout<<x<<" ";
        
        if(p_freq==window){
            ans.push_back(0);
        }
        for(int i=p_len;i<s_len;i++){
            window[s[i]-'a']++;
            window[s[i-p_len]-'a']--;
            if(p_freq==window){
                ans.push_back(i-p_len+1);
            }
        }
        return ans;
    }
};