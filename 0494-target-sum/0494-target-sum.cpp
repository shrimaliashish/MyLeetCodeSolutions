class Solution {
public:
    int ans=0;
    // vector<vector<int>>dp;
    map<pair<int,int>,int>dp;
    int fun(int i,int target,vector<int>& nums){
        if(i<0 && target==0)
            return 1;
        if(i<0)
            return 0;
        if(dp.count({i,target}))
            return dp[{i,target}];
        int cnt=0;
        cnt+=fun(i-1,target-nums[i],nums);
        cnt+=fun(i-1,target+nums[i],nums);
        return dp[{i,target}]=cnt;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        // dp.resize(n,vector<int>(target+1,-1));
        return fun(n-1,target,nums);
    }
};