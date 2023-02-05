class Solution {
public:
    vector<int> PSE(vector<int> &a){
        int iden = -1;
         vector<int> pse(a.size());
         stack<int> st; //please put indexes in the index
         for(int i = 0 ;i< a.size(); i++){
         while(!st.empty() && a[st.top()] >= a[i]) st.pop();
         if(!st.empty()) pse[i] = st.top(); else pse[i] = iden;
         st.push(i);
         }
    return pse;
    }
    vector<int> NSE(vector<int> &a){
        int iden = -1;
         vector<int> nse(a.size());
         stack<int> st;
         for(int i = a.size() - 1 ;i>=0; i--){
         while(!st.empty() && a[st.top()] > a[i]) st.pop();
         if(!st.empty()) nse[i] = st.top(); else nse[i] = iden;
         st.push(i);
         }
    return nse;
    }
   
    int sumSubarrayMins(vector<int>& arr) {
        int mod=1e9+7;
        int n = arr.size();
        // 3 1 2 4 
        //pse- -1 -1 1 2
        //nse-  1 -1  -1  -1
        // sum = 3 + 2 + 2 + 4 + 4 = 15 
        vector<int> pse = PSE(arr);
        vector<int> nse = NSE(arr);
        cout<<"pse is=>" <<' ';
        for(auto x: pse) cout<<x<<' ';
        cout<<endl<<"nse is=>" <<' ';
        for(auto x: nse) cout<<x<<' ';
        cout<<endl;
        int sum = 0;
        //add up each element contribution
        // see left, upto where it contributes to become smallest <a[i] ... a[i] .....<a[i]
        //total no of subarray will be the length between them - 1
        for(int i=0; i<n; i++){
            int right=nse[i]!=-1? nse[i]-i:n-i;
            int left=pse[i]!=-1? i-pse[i]:i+1;
            // cout<<arr[i]*(left)*(right)<<" ";
            sum=(sum+(long long)((long long)(arr[i]*left)%mod*right)%mod)%mod;

        }
        return sum;

    }
};