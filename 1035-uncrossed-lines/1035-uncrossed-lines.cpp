class Solution {
public:
    int fun(int i,int last,vector<int>& nums1, map<int,vector<int>>&m,vector<vector<int>>&dp){
        if(i==nums1.size()){
            return 0;
        }
        if(dp[i][last+1]!=-1){
            return dp[i][last+1];
        }
        int take=0,notTake=0;
        if(m.count(nums1[i])){
            int pos=-1;
            for(int j=0;j<m[nums1[i]].size();j++){
                if(m[nums1[i]][j]>last){
                    pos=m[nums1[i]][j];
                    break;
                }
            }
            if(pos!=-1){
                take=1+fun(i+1,pos,nums1,m,dp);
            }
        }
        notTake=0+fun(i+1,last,nums1,m,dp);
        return dp[i][last+1]= max(take,notTake);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size()+1,-1));
        map<int,vector<int>>m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]].push_back(i);
        }
        return fun(0,-1,nums1,m,dp);
    }
};
