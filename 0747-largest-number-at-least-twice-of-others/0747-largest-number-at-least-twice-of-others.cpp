class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int ind=max_element(begin(nums),end(nums))-begin(nums);
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(2*nums[n-2]>nums[n-1]) return -1;else return ind;
    }
};