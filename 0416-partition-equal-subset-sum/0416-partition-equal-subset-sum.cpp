class Solution {
public:
        bool find(int idx , int sum , vector<int>&arr , vector<vector<int>>&dp ){

        

        if( sum == 0 ) return true;

        if( idx == 0 )

           return arr[0] == sum;

        

        if( dp[idx][sum] != -1 ) return dp[idx][sum];

           

        bool ntake = find(idx-1 , sum , arr, dp);

        

        bool take = false;

        if( arr[idx] <= sum )

          take = find( idx-1 , sum-arr[idx] , arr ,dp );

          

        return dp[idx][sum] = ntake||take;

    }

 

    bool isSubsetSum(vector<int>&arr, int sum){

        

        int n = arr.size();

        vector<vector<int>> dp(n , vector<int>(sum+1 , -1));

        

        return find(n-1,sum,arr,dp); 

        

    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2) return false;
        return isSubsetSum(nums,sum/2);
    }
};