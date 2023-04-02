class Solution {
public:
    
    int fun(int L,int R,vector<int>& nums,vector<vector<int>>&dp){
        int mx=-1e9;
        if(L>R){
            return 0;
        }
        if(dp[L][R]!=-1)
            return dp[L][R];
        for(int i=L;i<=R;i++){
            int left=L-1>=0?nums[L-1]:1;
            int right=R+1<nums.size()?nums[R+1]:1;
            mx=max(mx,fun(L,i-1,nums,dp)+fun(i+1,R,nums,dp)+left*nums[i]*right);
        }
        return dp[L][R]= mx;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(0,n-1,nums,dp);
    }
};

// int coins = nums[i-1] * nums[ind] * nums[j+1] + f(i,ind-1,nums) + f(ind+1,j,nums);
//             maxi = max(maxi,coins);












