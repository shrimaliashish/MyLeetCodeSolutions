class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maximumSum=0,count=0;
        for(int i:nums){
            if(i==1)
                count++;
            else{
                maximumSum=max(count,maximumSum);
                count=0;
            }
        }
        maximumSum=max(count,maximumSum);
        return maximumSum;
    }
};