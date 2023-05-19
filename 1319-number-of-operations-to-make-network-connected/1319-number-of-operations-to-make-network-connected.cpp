class Solution {
public:
    int edgeCnt=0,nodeCnt=0,ExtraEdges=0;
    void dfs(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        for(auto child:adj[node]){
            if(!vis[child]){
                nodeCnt++;
                dfs(child,adj,vis);
            }
            edgeCnt++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        vector<int>vis(n,0);
        int c1=0,cnt=0;
        for(auto x:connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<adj[i].size();j++)
        //         cout<<adj[i][j]<<" ";
        //     cout<<endl;
        // }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                nodeCnt++;
                dfs(i,adj,vis);
                if(edgeCnt>=nodeCnt)
                    c1++;
                cnt++;
                ExtraEdges+=(edgeCnt/2)-nodeCnt+1;
                cout<<edgeCnt<<" "<<ExtraEdges<<" "<<nodeCnt<<endl;
                nodeCnt=0;
                edgeCnt=0;
            }
        }
        // cout<<c1<<" "<<cnt<<endl;
        int required=cnt-c1+(c1-1);
        return ExtraEdges>=required?required:-1;
    }
};