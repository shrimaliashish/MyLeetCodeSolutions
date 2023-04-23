//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    static bool cmp(pair<int,int>&p1,pair<int,int>&p2){
        return p1.second<p2.second;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
        int flag=0,k;
    	vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({arr[i],dep[i]});
        }
        sort(v.begin(),v.end());
        multiset<int>st;
        st.insert(-1); 
        // departure time of each train at platforms
        // let st={0910, 1020 } denotes two platforms having trains which will depart at following times
        // 0910 ->departure time of train at first platform
        // 1020 ->departure time of train at second platform
        for(auto x:v){
            // x will denote each train's arrrival and departure time
            flag=0;
            for(auto y:st){
                if(y<x.first){
                    // k=y;
                    auto itr=st.find(y);
                    st.erase(itr);
                    st.insert(x.second);
                    flag=1;
                    break;
                }
            }
            
            if(flag==0){
                st.insert(x.second);
            }
            // else{
            //     auto itr=st.find(k);
            //     st.erase(itr);
            //     st.insert(x.second);
            // }
        }
        return st.size();
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends