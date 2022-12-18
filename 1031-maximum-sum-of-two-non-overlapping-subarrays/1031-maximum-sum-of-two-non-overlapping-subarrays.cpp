class Solution {
public:
    int solve(vector<int>v,int x,int y){
        int n=v.size(),sum=0;;
        vector<int>dp1(n),dp2(n);
        for(int i=0;i<n;i++){
            if(i<x){
                sum+=v[i];
                dp1[i]=sum;
            }else{
                sum-=v[i-x];
                sum+=v[i];
                dp1[i]=max(dp1[i-1],sum);
            }
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            if(i+y>=n){
                sum+=v[i];
                dp2[i]=sum;
            }else{
                sum-=v[i+y];
                sum+=v[i];
                dp2[i]=max(dp2[i+1],sum);
            }
        }
        sum=0;
        for(int i=x-1;i<n-y;i++){
            sum=max(sum,dp1[i]+dp2[i+1]);
        }
        return sum;
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int x, int y) {
        int mx1=solve(nums,x,y);
        int mx2=solve(nums,y,x);
        return max(mx1,mx2);
    }
};