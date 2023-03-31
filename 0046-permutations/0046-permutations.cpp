class Solution {
public:
    vector<vector<int>>ans;
    int n;
    vector<int>a;
    void solve(int i,set<int>st,vector<int>ds){
        if(i==n){
            ans.push_back(ds);
            return ;
        }
        for(int j=0;j<n;j++){
            if(st.find(a[j])==st.end()){
                st.insert(a[j]);
                ds.push_back(a[j]);
                solve(i+1,st,ds);
                st.erase(a[j]);
                ds.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        a=nums;
        set<int>st;
        vector<int>ds;
        n=nums.size();
        solve(0,st,ds);
        return ans;
    }
};