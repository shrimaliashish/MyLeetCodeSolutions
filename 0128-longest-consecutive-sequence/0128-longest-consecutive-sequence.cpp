class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size(),cnt=1,mx=0,prev=-1;
        if(n<=1)
            return n;
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]=1;
        }
        int mn=m.begin()->first,maxi=m.rbegin()->first;
        // cout<<mn<<" "<<maxi<<endl;
        for(auto itr=m.begin();itr!=m.end();itr++){
            if(itr==m.begin()){
                prev=itr->first;
                continue;
            }
            if(itr->first==prev+1){
                cnt++;
            }else{
                mx=max(mx,cnt);
                cnt=1;
            }
            prev=itr->first;
        }
         mx=max(mx,cnt);
        return mx;
    }
};