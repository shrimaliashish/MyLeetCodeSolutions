class Solution {
private:
    int n,m,ct;
    void dfs(int src,vector<bool>&vis,vector<int> g[]){
        vis[src] = true;
        for(auto &child: g[src]){
            if(!vis[child]){
                dfs(child,vis,g);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size(), m = isConnected[0].size(), ct = 0;
        vector<bool> vis(n+1,false);
        vector<int> g[n+1];
        for(int i=0; i<n; ++i){
            for(int j=0; j<m; ++j){
                if(i==j) continue;
                if(isConnected[i][j])
                    g[i+1].push_back(j+1);
            }
        }
        for(int i=1; i<=n; ++i){
            if(!vis[i]){
                dfs(i,vis,g);
                ct++;
            }
        }
        return ct;
    }
};