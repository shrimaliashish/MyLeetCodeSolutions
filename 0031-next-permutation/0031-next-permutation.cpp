class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int j=n,prev=nums[n-1];
        for(int i=n-1;i>=0;i--){
            if(nums[i]<prev){
                j=i;
                break;
            }
            prev=nums[i];
        }
        if(j==n)
        {
            sort(nums.begin(),nums.end());
            return ;
        }
        // cout<<j<<endl;
        sort(nums.begin()+j+1,nums.end());
        // for(auto x:nums)
        // cout<<x<<endl;
        int lb=upper_bound(nums.begin()+j+1,nums.end(),nums[j])-nums.begin();
        cout<<lb<<endl;
        swap(nums[j],nums[lb]);
    }
};