class Solution {
public:
    bool check(vector<int>& a, int k,int mid){
        int n=a.size();
        int sum=0,cnt=1;
        for(int i=0;i<n;i++){
            if(sum+a[i]<=mid){
                sum+=a[i];
            }else{
                sum=a[i];
                cnt++;
            }
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& a, int k) {
        int n=a.size();
        if(k>n)
        return -1;
        int low=a[0],high=0,ans=-1;
        for(int i=0;i<n;i++){
            high+=a[i];
            low=max(low,a[i]);
        }
        while(low<=high){
            int mid=(high+low)/2;
            if(check(a,k,mid)){
                ans=mid;
                high=mid-1;
            }else low=mid+1;
        }
        return ans;
    }
};