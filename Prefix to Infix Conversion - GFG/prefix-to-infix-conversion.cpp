//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToInfix(string ex) {
        int n=ex.size();
        stack<string>st;
        for(int i=n-1;i>=0;i--){
            if(ex[i]=='+' || ex[i]=='-' ||ex[i]=='*'|| ex[i]=='/' || ex[i]=='^'){
                string a=st.top();
                st.pop();
                string b=st.top();
                st.pop();
                string res='('+a+ex[i]+b+')';
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
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends