class Solution {
public:
    int dp[10001];
    int rec(vector<int> & a, int ind){
        if(ind >= a.size()-1){
            return 0;
        }
        int &ans = dp[ind];
        if(ans != -1) return ans;
        ans = 1e9;
        for(int x= ind+1; x<=min((int)a.size(),ind+a[ind]); x++){
            ans = min(ans,1+rec(a,x));
        }
        return ans;
    }
    int jump(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        //lets consider dp(i) min steps required to reach n-1 from i
        return rec(nums, 0);
    }
};