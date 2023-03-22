class Solution {
public:
    // vector<vector<int>>ans;
    // void solve(int i,int target,int cap,vector<int>& nums,vector<int>&ds){
    //     int n=nums.size();
    //     if(target==0 && cap==0){
    //         ans.push_back(ds);
    //         return;
    //     }
    //     if(i==n || cap==0)
    //         return;
    //     ds.push_back(nums[i]);
    //     solve(i+1,target-nums[i],cap-1,nums,ds);
    //     ds.pop_back();
    //     solve(i+1,target,cap,nums,ds);
    // }
    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //     int n=nums.size();
    //     vector<vector<int>>dp(n,vector<int>(4,-1));
    //     vector<int>ds;
    //     solve(0,target,4,nums,ds);
    //     return ans;
    // } 
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int low=j+1,high=n-1;
                while(low<high){
                    long long int sum=nums[low]+nums[high];
                    long long int newTarget=(long long)target-(long long)nums[i]-(long long)nums[j];
                    if(sum==newTarget){
                        st.insert({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;
                    }else if(sum<newTarget){
                        low++;
                    }else high--;
                }
            }
        }
        for(auto x:st)
            ans.push_back(x);
        return ans;
    }
};