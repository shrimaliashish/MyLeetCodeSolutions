class Solution {
public:
    bool isPalindrome(string str){
        string temp=str;
        reverse(str.begin(),str.end());
        return temp==str;
    }
    
    
    pair<int,string> check(string str,int k){
        
        //case1
        int i=k,j=k;
        while(i>=0 && j<str.length() && str[i]==str[j]){
            i--;
            j++;
        }
        i++;
        j--;
        // cout<<i<<" "<<j<<endl;
        pair<int,string>p1,p2,p3;
        p1={j-i+1,str.substr(i,j-i+1)};
        
        //case2
        i=k,j=k+1;
        while(i>=0 && j<str.length() && str[i]==str[j]){
            i--;
            j++;
        }
        if(i!=k)
        i++;
        j--;
        
        p2={j-i+1,str.substr(i,j-i+1)};
        
        //case3
        i=k-1,j=k;
        while(i>=0 && j<str.length() && str[i]==str[j]){
            i--;
            j++;
        }
        i++;
        if(j!=k)
        j--;
        
        p3={j-i+1,str.substr(i,j-i+1)};
        return max({p1,p2,p3});
    }
    
    string longestPalindrome(string str) {
        int n=str.size();
        vector<int>dp(n,-1);
        int mx=0;
        string ans="";
        for(int i=0;i<n;i++){
            pair<int,string>temp=check(str,i);
            // cout<<temp.first<<" "<<temp.second<<endl;
            if(temp.first>mx){
                mx=temp.first;
                ans=temp.second;
            }
        }
        
        
        // cout<<k<<endl;
        return ans;
        
    }
};