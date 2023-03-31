class Solution {
public:
    vector<vector<int>>optimal_cut;
    vector<vector<int>>dp;
    int solve(int l,int r,vector<int>&cuts){
        if(r-l+1<=2)
            return 0;
        int &ans=dp[l][r];
        if(ans!=-1)
            return ans; 
        int mn=INT_MAX;
        for(int k=l+1;k<r;k++){
            int cur_sum=solve(l,k,cuts)+solve(k,r,cuts)+cuts[r]-cuts[l];
            // cout<<l<<" "<<r<<" "<<cur_sum<<endl;
            // if(cur_sum<ans){
            //     ans=cur_sum;
            //     optimal_cut[l][r]=k;
            // }
            mn=min(mn,cur_sum);
        }
        return ans=mn;
    }
    int minCost(int n, vector<int>& cuts) {
        vector<int>points;
        points.push_back(0);
        for(int p : cuts) points.push_back(p);
        points.push_back(n);
        sort(points.begin(),points.end());
        int N=points.size();
        // optimal_cut=vector<vector<int>>(N,vector<int>(N,INT_MAX));
        dp=vector<vector<int>>(N,vector<int>(N,-1));
        return solve(0,N-1,points);
    }
};