class Solution {
public:
    int fun(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
        if(i==nums1.size() || j==nums2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int take=0;
        if(nums1[i]==nums2[j])
            take=1+fun(i+1,j+1,nums1,nums2,dp);
        fun(i,j+1,nums1,nums2,dp);
        fun(i+1,j,nums1,nums2,dp);
        
        if(nums1[i]==nums2[j])dp[i][j]=take;
        else dp[i][j]=0;
        return dp[i][j];
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
         fun(0,0,nums1,nums2,dp);
        int mx=0;
        for(int i=0;i<nums1.size();i++)
            for(int j=0;j<nums2.size();j++)mx=max(mx,dp[i][j]);
        
        return mx;
    }
};