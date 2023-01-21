//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string postToPre(string ex) {
        int n=ex.size();
        stack<string>st;
        for(int i=0;i<n;i++){
            if(ex[i]=='+' || ex[i]=='-' ||ex[i]=='*'|| ex[i]=='/' || ex[i]=='^'){
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                string res=ex[i]+b+a;
                st.push(res);
            }else{
                string t;
                t.push_back(ex[i]);
                st.push(t);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends