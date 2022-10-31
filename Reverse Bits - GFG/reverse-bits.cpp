//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long  decimal(string str)
    {
      long long  res=0,d=1;
      for(int i=str.length()-1;i>=0;i--)
      {
        if(str[i]=='1')
        {
          res+=d;
        }
        d*=2;
      }
      return res;
    }
    string binary(long long n)
    {
        string binary = bitset<32>(n).to_string();
        return binary;
    }
    long long reversedBits(long long num) {
       string str=binary(num);
       reverse(str.begin(),str.end());
       return decimal(str);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends