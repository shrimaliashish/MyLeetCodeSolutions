class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0];
        int profit=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]>mn){
                profit=max(profit,prices[i]-mn);
            }
            mn=min(mn,prices[i]);
        }
        return profit;
    }
};