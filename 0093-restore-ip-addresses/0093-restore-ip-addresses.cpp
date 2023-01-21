class Solution {
public:
    void getIPs(string s,int i,int dot_cnt,string ds,vector<string>&ans){
        int n=s.size();
        if(i>=n)
            return;
        if(dot_cnt==3){
            string temp=s.substr(i);
            int sz=temp.length();
            if(sz>3)
                return;
            if(sz==3){
                if(stoi(temp)>99 && stoi(temp)<256){
                    ds=ds+temp;
                    ans.push_back(ds);
                }
            }else if(sz==2){
                if(stoi(temp)>9){
                    ds=ds+temp;
                    ans.push_back(ds);
                }
            }else if(sz==1){
                ds=ds+temp;
                ans.push_back(ds);
            }
            return;
        }
        
        ds.push_back(s[i]);
        ds.push_back('.');
        getIPs(s,i+1,dot_cnt+1,ds,ans);
        ds.pop_back();
        ds.pop_back();
        
        if(i+1<n){
            int z=stoi(s.substr(i,2));
            if( z>9){
                ds.push_back(s[i]);
                ds.push_back(s[i+1]);
                ds.push_back('.');
                getIPs(s,i+2,dot_cnt+1,ds,ans);
                ds.pop_back();
                ds.pop_back();
                ds.pop_back();
            }
        }
        
        if(i+2<n){
            int z=stoi(s.substr(i,3));
            if( z>99 && z<256){
                ds.push_back(s[i]);
                ds.push_back(s[i+1]);
                ds.push_back(s[i+2]);
                ds.push_back('.');
                getIPs(s,i+3,dot_cnt+1,ds,ans);
                ds.pop_back();
                ds.pop_back();
                ds.pop_back();
                ds.pop_back();
            }
            
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string ds="";
        getIPs(s,0,0,ds,ans);
        return ans;
    }
};