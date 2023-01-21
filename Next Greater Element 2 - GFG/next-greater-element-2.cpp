//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> nextGreaterElement(int n, vector<int>& arr) {
       vector<int>ans(n,0);
        stack<int>st;
        for(int i=n-1;i>-n;i--){
            // cout<<(i+n)%n<<endl;
            if(st.empty()){
                ans[(i+n)%n]=-1;
                st.push(arr[(i+n)%n]);
            }else{
                while(!st.empty() && st.top()<=arr[(i+n)%n]){
                    st.pop();
                }
                if(st.empty()){
                    ans[(i+n)%n]=-1;
                    st.push(arr[(i+n)%n]);
                }else{
                    ans[(i+n)%n]=st.top();
                    st.push(arr[(i+n)%n]);
                }
            }
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

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends