class Solution {
public:
    int f(int i, int tar, vector<int>&nums, vector<vector<int>>&dp) {
        if(i==0) {
            if(tar==0 && nums[0] == 0) return 2;
            if(tar==nums[0] || tar==0) return 1;
            else return 0;
        }
        if(dp[i][tar]!=-1) return dp[i][tar];
        int notTake = f(i-1, tar, nums, dp);
        int take = 0;
        if(tar >= nums[i]) take = f(i-1, tar-nums[i], nums, dp);
        return dp[i][tar] = (take+notTake);
    }
    int findWays(vector<int> &nums, int tar){
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(tar+1, -1));
        return f(n-1, tar, nums, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        if(totSum - target < 0 || (totSum-target)%2 != 0) return 0;
        return findWays(nums, (totSum - target)/2);
    }
};