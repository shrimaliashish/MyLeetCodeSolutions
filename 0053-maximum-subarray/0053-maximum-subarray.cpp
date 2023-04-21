class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=nums[0],r=0,n=nums.size(),mx=nums[0];
        for(int i=1;i<n;i++){
            sum+=nums[i];
            if(sum<nums[i])
                sum=nums[i];
            mx=max(sum,mx);
        }
        return mx;
    }
};