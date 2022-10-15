class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int mx=0;
        for(auto x:s){
            if(x=='(')
                st.push('(');
            else if(!st.empty() && x==')')
            {
                st.pop();
            }
            if(!st.empty())
            mx=max(mx,(int)st.size());
        }
        return mx;
    }
};