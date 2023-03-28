//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>dp;
    int solve(int i,int w, int wt[], int val[], int n){
        if(i<0 || w<=0)
            return 0;
        if(dp[i][w]!=-1)
            return dp[i][w];
        int take=0;
        if(wt[i]<=w){
            take=max(val[i]+solve(i-1,w-wt[i],wt,val,n),val[i]+solve(i,w-wt[i],wt,val,n));
        }
        int notTake=solve(i-1,w,wt,val,n);
            return dp[i][w]= max(take,notTake);
            // return  max(take,notTake);
    }
    int knapSack(int n, int W, int val[], int wt[])
    {
        dp=vector<vector<int>>(n,vector<int>(W+1,-1));
       return solve(n-1,W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends