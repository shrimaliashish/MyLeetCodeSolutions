class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,n=s.size(),ans=0,cnt=0,total=0;
        map<char,int>m;
        while(r<n){
            m[s[r]]++;
            cnt=0;
            total=0;
            for(auto x:m){
                total+=x.second;
                cnt=max(x.second,cnt);
            }
            cnt=total-cnt;
            while(m.size()>1 && cnt>k){
                if(m[s[l]]>1){
                    m[s[l]]--;
                }else
                m.erase(s[l]);
                l++;
                total=0;
                cnt=0;
                for(auto x:m){
                    total+=x.second;
                    cnt=max(x.second,cnt);
                }
                cnt=total-cnt;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};