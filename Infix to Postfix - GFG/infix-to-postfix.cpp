//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        stack<char>st;
        string ans="";
        for(auto x:s){
            if(x=='('){
                st.push('(');
            }else if(x==')'){
                while(st.top()!='('){
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }else if(x=='^'){
                st.push('^');
            }else if(x=='*' || x=='/'){
                if(st.empty() || st.top()=='+' || st.top()=='-' || st.top()=='('){
                    st.push(x);
                }else{
                    ans.push_back(st.top());
                    st.pop();
                    st.push(x);
                }
            }else if(x=='+' || x=='-'){
                
                if(st.empty() || st.top()=='('){
                    st.push(x);
                }else{
                    while(!st.empty() && (st.top()=='*' || st.top()=='/' || st.top()=='^')){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    if(!st.empty() && (st.top()=='+'|| st.top()=='-')){
                        ans.push_back(st.top());
                        st.pop();
                    }
                    st.push(x);
                }
            }else{
                ans.push_back(x);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends