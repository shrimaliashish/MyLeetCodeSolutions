class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int l=0,mx=0;
        int n=s.length();
        for(int j=0;j<n;j++){
            m[s[j]]++;
            while(m[s[j]]>1){
                m[s[l]]--;
                l++;
            }
            mx=max(mx,j-l+1);
        }
        return mx;
    }
};