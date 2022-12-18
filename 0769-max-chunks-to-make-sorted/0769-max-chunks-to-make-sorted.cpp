class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size(),cnt=0,sum=0;
       for(int i=0;i<n;i++){
           int k=(i)*(i+1)/2;
           sum+=arr[i];
           if(k==sum)cnt++;
       }
        return cnt;
    }
};