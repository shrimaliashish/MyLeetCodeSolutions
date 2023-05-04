//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int>ans;
// 	void dfs(vector<int> adj[],vector<int>&vis,int node){
// 	    vis[node]=1;
// 	    for(auto child:adj[node]){
// 	        if(!vis[child]){
// 	            dfs(adj,vis,child);
// 	        }
// 	    }
// 	    ans.push_back(node);
// 	}

// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    vector<int>vis(V,0);
// 	    for(int i=0;i<V;i++)
//          {
//              if(!vis[i])
//              {
//                  dfs(adj,vis,i);
//              }
//          }
// 	    reverse(ans.begin(),ans.end());
// 	    return ans;
// 	}
	void bfs(vector<int> adj[],vector<int>&indegree){
	   queue<int>q;
	   for(int i=0;i<indegree.size();i++){
	       if(indegree[i]==0)
	       {
	           q.push(i);
	           //ans.push_back(i);
	       }
	   }
	   while(!q.empty()){
	       int front=q.front();
	       q.pop();
	       ans.push_back(front);
	       for(auto child:adj[front]){
	           indegree[child]--;
	           if(indegree[child]==0){
	               q.push(child);
	               
	           }
	       }
	   }
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int>indegree(V,0);
	    for(int i=0;i<V;i++){
	        for(auto child:adj[i]){
	            indegree[child]++;
	        }
	    }
	    vector<int>vis(V,0);
        bfs(adj,indegree);
	   // reverse(ans.begin(),ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends