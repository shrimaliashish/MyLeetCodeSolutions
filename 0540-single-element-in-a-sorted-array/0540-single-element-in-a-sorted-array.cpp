class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1,ans=-1;
        if(nums.size()==1)return nums[0];
        while(low<=high){
            int mid=low+(high-low)/2;
            if(mid%2){
                if(nums[mid]==nums[mid-1])
                    low=mid+1;
                else {
                    ans=mid;
                  high=mid-1;
                    
                }
            }else{
                if(mid+1<nums.size() && nums[mid]==nums[mid+1])
                    low=mid+1;
                else{
                    ans=mid;
                  high=mid-1;
                }
            }
        }
        return nums[high+1];
    }
};