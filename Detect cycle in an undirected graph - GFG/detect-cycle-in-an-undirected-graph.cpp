//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    // bool dfs(int node,int parent,vector<int> adj[],vector<int>&vis){
    //     vis[node]=1;
    //     for(auto child:adj[node]){
    //         if(vis[child] && child!=parent){
    //             return true;
    //         }else if(!vis[child]){
    //             if(dfs(child,node,adj,vis)){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    // bool isCycle(int n, vector<int> adj[]) {
    //     vector<int>vis(n,0);
    //     bool ans=false;
    //     for(int i=0;i<n;i++){
    //         if(!vis[i])
    //         ans=ans || dfs(i,-1,adj,vis);
    //     }
    //     return ans;
    // }
    
    bool bfs(int node,vector<int>adj[],vector<int>&vis){
        unordered_map<int, int> parent;
        queue<int>q;
        q.push(node);
        parent[node]=-1;
        vis[node]=1;
        while(!q.empty()){
            int sz=q.size();
            int temp=q.front();
                q.pop();
                vis[temp]=1;
                for(auto child:adj[temp]){
                    if(vis[child] && child!=parent[temp])
                    return true;
                    else if(!vis[child]) {
                        // vis[child]=1;
                        parent[child]=temp;
                        q.push(child);
                    }
                }
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        vector<int>vis(n,0);
        bool ans=false;
        for(int i=0;i<n;i++){
            if(!vis[i])
            ans=ans || bfs(i,adj,vis);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends