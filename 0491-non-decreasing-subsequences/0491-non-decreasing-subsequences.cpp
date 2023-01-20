class Solution {
public:
    void solve(int i,vector<int>& nums,vector<vector<int>>&ans,vector<int>&ds){
        if(i==nums.size()){
            if(ds.size()>1)
            ans.push_back(ds);
            return;
        }
        if(ds.size()==0 || nums[i]>=ds.back()){
            ds.push_back(nums[i]);
            solve(i+1,nums,ans,ds);
            ds.pop_back();
        }
        if(ds.empty() || nums[i]!=ds.back()){
            solve(i+1,nums,ans,ds);
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>v;
        vector<int>ds;
        solve(0,nums,v,ds);
        return v;
    }
};