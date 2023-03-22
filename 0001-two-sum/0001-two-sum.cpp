class Solution {
public:
    set<int>st;
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]].push_back(i);
        sort(nums.begin(),nums.end());
        int low=0,high=nums.size()-1;
        while(low<high){
            int sum=nums[low]+nums[high];
            if(sum==target)
            {
                if(nums[low]==nums[high]){
                    st.insert(m[nums[low]][0]);
                    st.insert(m[nums[low]][1]);
                }else{
                    st.insert(m[nums[low]][0]);
                    st.insert(m[nums[high]][0]);
                }
                low++;
                high--;
                    
            }else if(sum<target){
                low++;
            }else{
                high--;
            }
        }
        vector<int>v;
        for(auto x:st)
            v.push_back(x);
        return v;
    }
};