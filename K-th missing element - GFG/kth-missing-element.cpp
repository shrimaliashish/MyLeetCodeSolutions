//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    int beg = 0, end = n-1;
    
    while(beg <= end){
        
        int mid = (beg + end) >> 1;
        
        int missing_till_mid = a[mid] - (mid + a[0]);
        
        if(missing_till_mid < k)
            beg = mid + 1;
            
        else //missing_till_mid >= k
            end = mid - 1;
    }
    
    if(beg == n)
        return - 1;
        
    else
        return (beg-1 + a[0] + k);

}