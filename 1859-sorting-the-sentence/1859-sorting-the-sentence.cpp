class Solution {
public:
    string sortSentence(string str2){
        stringstream s(str2);
        string word;
        map<int,string>m;
        while(s>>word){
            int n=word.length();
            m[word[n-1]-'0']=word;
        }
        string ans="";
        for(auto x:m){
            string str=x.second;
            str.pop_back();
            ans+=(str);
            ans.push_back(char(32));
        }
        ans.pop_back();
        return ans;
    }
};