//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    vector<int>dp;
	int getMax(int i,int *a,int n){
	    if(i>=n)
	    return 0;
	    if(dp[i]!=-1)
	    return dp[i];
	    int take=a[i]+getMax(i+2,a,n);
	    int notTake=getMax(i+1,a,n);
	    return dp[i]= max(take,notTake);
	}
    int FindMaxSum(int a[], int n)
    {
        dp=vector<int>(n,-1);
	    return getMax(0,a,n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends