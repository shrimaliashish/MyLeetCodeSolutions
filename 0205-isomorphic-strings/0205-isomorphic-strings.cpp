class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,vector<int>>m;
        for(int i=0;i<s.size();i++){
            m[s[i]].push_back(i);
        }
        for(auto x:m){
            for(int i=1;i<x.second.size();i++){
                if(t[x.second[i]]!=t[x.second[i-1]])
                    return false;
            }
        }
        m.clear();
        for(int i=0;i<t.size();i++){
            m[t[i]].push_back(i);
        }
        
        for(auto x:m){
            for(int i=1;i<x.second.size();i++){
                if(s[x.second[i]]!=s[x.second[i-1]])
                    return false;
            }
        }
        return true;
    }
};