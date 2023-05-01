class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        map<int,int>mp;
        int sum=0,ans=0;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            // ans+=mp[k-nums[i]%k]+mp[nums[i]%k];
            sum=(sum%k+nums[i]%k+k)%k;
            ans+=mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};

// 4 5 0 -2 -3 1
