//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int a, int b, int c, int d){
        int carpet_mx=max(a,b),carpet_mn=min(a,b);
        int box_mx=max(c,d),box_mn=min(c,d);
        int cnt=0;
        while(carpet_mx>box_mx || carpet_mn>box_mn){
            if(carpet_mx>box_mx){
                carpet_mx/=2;
            }else if(carpet_mn>box_mn){
                carpet_mn/=2;
            }
            int temp_mx=carpet_mx;
            int temp_mn=carpet_mn;
            carpet_mx=max(temp_mx,temp_mn);
            carpet_mn=min(temp_mx,temp_mn);
            cnt++;
        }
        // carpet_mx=max(carpet_mx,carpet_mn);
        // carpet_mn=min(carpet_mx,carpet_mn);
        // box_mx=max(box_mx,box_mn);
        // box_mn=min(box_mx,box_mn);
        // while(carpet_mn>box_mn){
        //     carpet_mn/=2;
        //     cnt++;
        // }
        
        return cnt;
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends