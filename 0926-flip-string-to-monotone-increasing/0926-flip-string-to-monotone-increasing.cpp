class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int zero_cnt[n],one_cnt[n];
        memset(zero_cnt,0,sizeof(zero_cnt));
        memset(one_cnt,0,sizeof(one_cnt));
        if(s[0]=='1')one_cnt[0]=1;
        for(int i=1;i<n;i++){
            if(s[i]=='1')
                one_cnt[i]=one_cnt[i-1]+1;
            else
                one_cnt[i]=one_cnt[i-1];
        }
        if(s[n-1]=='0')zero_cnt[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0')
                zero_cnt[i]=zero_cnt[i+1]+1;
            else
                zero_cnt[i]=zero_cnt[i+1];
        }
        // for(auto x:zero_cnt)
        //     cout<<x<<" ";
        // cout<<endl;
        // for(auto x:one_cnt)
        //     cout<<x<<" ";
        // cout<<endl;
        int mx=INT_MAX;
        for(int i=0;i<n;i++){
            mx=min(one_cnt[i]+zero_cnt[i]-1,mx);
            // cout<<mx<<" ";
        }
        // cout<<endl;
        return mx;
    }
    
};
