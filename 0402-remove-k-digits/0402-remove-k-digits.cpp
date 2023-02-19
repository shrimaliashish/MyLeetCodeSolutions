class Solution {
public:
    string removeKdigits(string num, int k) {
        string str="";
        int cnt=0;
        for(auto x:num){
            if(str.length()==0){
                str.push_back(x);
            }else {
                while( str.length()>0 && cnt<k && x<str[str.length()-1]){
                    str.pop_back();
                    cnt++;
                }
                str.push_back(x);
            }
            // cout<<str<<endl;
        }
        while(cnt<k){
            str.pop_back();
            cnt++;
        }
        int i=0;
        while(str[i]=='0'){
            i++;
        }
        return str.substr(i)==""?"0":str.substr(i);
    }
};