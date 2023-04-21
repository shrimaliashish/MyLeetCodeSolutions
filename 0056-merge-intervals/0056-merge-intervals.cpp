class Solution {
public:
    bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(ans.back()[1]<intervals[i][0]){
                ans.push_back(intervals[i]);
            }else if(ans.back()[1]>=intervals[i][0] && ans.back()[1]<intervals[i][1]){
                ans.back()[1]=intervals[i][1];
            }
        }
        return ans;
    }
};