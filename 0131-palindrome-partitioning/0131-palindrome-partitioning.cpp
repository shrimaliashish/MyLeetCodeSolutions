class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string str){
        string rev=str;
        reverse(rev.begin(),rev.end());
        return str==rev;
    }
//     void partition(int i,int j,string str,vector<string>&ds){
//         int n=str.size();
//         if(i==j && j==n-1){
//             // string temp;
//             // temp.push_back(str[i]);
//             // ds.push_back(temp);
//             int sz=0;
//             for(auto x:ds){
//                 sz+=x.size();
//             }
//             if(sz==n)
//             ans.push_back(ds);
//             return;
//         }
//         if(i>=j)
//             return;
        
//         for(int k=i;k<j;k++){
//             string temp=str.substr(i,k-i+1);
//             if(isPalindrome(temp)){
//                 ds.push_back(temp);
//                 partition(i,k,str,ds);
//                 partition(k+1,j,str,ds);
//                 ds.pop_back();
//             }
//         }
        
//     }
    void partition(int ind,string & str,vector<string>&ds){
        int n=str.size();
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        for(int i=ind;i<n;i++){
            string temp=str.substr(ind,i-ind+1);
            if(isPalindrome(temp)){
                ds.push_back(temp);
                partition(i+1,str,ds);
                ds.pop_back();
            }
        }
            
    }
    vector<vector<string>> partition(string s) {
        vector<string>ds;
        // partition(0,s.size()-1,s,ds);
        partition(0,s,ds);
        return ans;
    }
};