class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0,cntZero=0,n=nums.size(),ans=0;
        while(right<n){
            if(nums[right]==0)
                cntZero++;
            while(cntZero>k){
                if(nums[left]==0)
                    cntZero--;
                left++;
            }
            
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};