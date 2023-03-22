class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0;i<n-2;i++){
            int low=i+1,high=n-1;
                while(low<high){
                    long long int sum=nums[low]+nums[high]+nums[i];
                    if(sum==target){
                        st.insert({nums[i],nums[low],nums[high]});
                        low++;
                        high--;
                    }else if(sum<target){
                        low++;
                    }else high--;
                }
        }
        for(auto x:st)
            ans.push_back(x);
        return ans;
    }
};