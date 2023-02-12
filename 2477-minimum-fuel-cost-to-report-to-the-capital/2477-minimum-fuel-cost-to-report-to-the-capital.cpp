class Solution {
public:
    long long ans = 0, s;
    int dfs(int node, int par,vector<vector<int>>& Graph){
        int reps = 1;
        for(int &x: Graph[node]){
            if(x == par) continue;
            reps += dfs(x, node, Graph);
        }
        if(node != 0) ans += (reps/s) + (reps%s != 0);
        return reps;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> Graph(roads.size() +1); s = seats;
        for(vector<int> &r: roads){
            Graph[r[0]].push_back(r[1]);
            Graph[r[1]].push_back(r[0]);
        }
        dfs(0,0,Graph);
        return ans;
    }
};