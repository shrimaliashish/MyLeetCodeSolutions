//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int count=0;
        void merge(vector<long long >& a1, long long  m, vector<long long >& a2, long long  n,vector<long long >& a) {
        long long  i,j,k;
        long long  b[a1.size()];
        for(i=0;i<m;i++)
            b[i]=a1[i];
        i=0,j=0,k=0;
        while(i<m && j<n)
        {
            if(b[i]<=a2[j])
                a[k++]=b[i++];
            else
                {
                    count+=(m-i);
                    a[k++]=a2[j++];
                    
                }
        }
        while(i<m)
        {
            a[k++]=b[i++];
        }
        while(j<n)
        {
            a[k++]=a2[j++];
        }
    }
void mergesort(vector<long long >&a,long long  l,long long  u)
{
    if(l<u)
    {
        long long  mid=l+(u-l)/2;
        vector<long long >b,c;
        for(long long  i=l;i<=mid;i++)
            b.push_back(a[i]);
        for (long long  i = mid+1; i <=u; ++i)
        {
            c.push_back(a[i]);
        }
        mergesort(b,0,b.size()-1);
        mergesort(c,0,c.size()-1);
        merge(b,b.size(),c,c.size(),a);
    }
    

}
    long long int inversionCount(long long  arr[], long long  N)
    {
    vector<long long >v(arr,arr+N);
       mergesort(v,0,N-1);
       return count;
    }


    
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends