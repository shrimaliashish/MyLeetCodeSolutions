class Solution {
public:
    int romanToInt(string str) {
        int n=str.size();
        char last=str[n-1];
        map<char,int>m;
        m['I']=1;
        m['V']=5;
        m['X']=10; 
        m['L']=50; 
        m['C']=100; 
        m['D']=500;
        m['M']=1000;
        int ans=0;
        for(int i=n-1;i>=0;i--){
            if(m[str[i]]>=m[last]){
                ans+=m[str[i]];
                last=str[i];
            }else{
             ans-=m[str[i]];
                last=str[i];
            }
        }
        return ans;
    }
};