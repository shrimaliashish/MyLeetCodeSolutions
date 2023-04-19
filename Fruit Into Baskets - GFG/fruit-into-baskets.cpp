//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int n, vector<int> &a) {
        int l=0,r=0,ans=0;
        map<int,int>mp;
        while(r<n){
            mp[a[r]]++;
            while(mp.size()>2){
                if(mp[a[l]]>1){
                    mp[a[l]]--;
                }else
                mp.erase(a[l]);
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends