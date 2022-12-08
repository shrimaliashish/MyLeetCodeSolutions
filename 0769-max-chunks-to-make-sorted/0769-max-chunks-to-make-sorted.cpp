class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        map<int,int>m;
        int n=arr.size();
        for(int i=0;i<n;i++){
            m[arr[i]]=i;
        }
        int last=-1,cnt=0;
        for(int i=0;i<n;i++){
            if(m[i]>last){
                last=m[i];
                A:;
                cnt++;
                int mx=-1;
                for(int j=i;j<=last;j++){
                    mx=max(mx,arr[j]);
                }
                if(mx>last){
                    cnt--;
                    last=mx;
                    goto A;
                }
                
            }
        }
        return cnt;
    }
};