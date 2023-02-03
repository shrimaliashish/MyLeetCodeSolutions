class Solution {
public:
    string convert(string str, int k) {
        int n=str.size();
        map<int,string>m;
        int flag=0,j=0;
        for(int i=0;i<n;i++){
            if(flag==0){
             m[j].push_back(str[i]);
                j++;
            }else if(flag==1){
                m[j].push_back(str[i]);
                j--;
            }
            if(j==0)
                flag=0;
            else if(j==k-1)
                flag=1;
        }
        string ans="";
        for(auto x:m){
            ans+=x.second;
        }
        return ans;
    }
};