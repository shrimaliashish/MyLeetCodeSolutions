class Solution {
public:
    bool check(string str){
        string rev=str;
        reverse(rev.begin(),rev.end());
        return rev==str;
    }
    void find(int i,int j,string s,vector<vector<string>>&ans,vector<string>&ds)
    {  
        int n=s.size();
        if(j==n){
            int sz=0;
            for(auto x:ds){
                sz+=x.size();
            }
            if(sz==n)
            ans.push_back(ds);
            return;
        }
        string temp=s.substr(i,j-i+1);
        if(check(temp)){
            ds.push_back(temp);
            find(j+1,j+1,s,ans,ds);
            ds.pop_back();
        }
        find(i,j+1,s,ans,ds);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        find(0,0,s,ans,ds);
        return ans;
    }
};
