class Solution {
public:
//     void dfs(int i,int j,int &cnt,int &flag,vector<vector<int>>&grid,vector<vector<int>>&vis){
//         int n=grid.size(),m=grid[0].size();
        
//         if((i==0 || i==n-1 || j==0 || j==m-1) && grid[i][j]==1 ){
//             cnt=0;
//             flag=0;
//             // vis[i][j]=1;
//             return ;
//         }
//         if(grid[i][j]==0 || vis[i][j]==1){
//             return;
//         }
//         if(i<0 || i==n || j<0 || j==m){
//             return;
//         }
            
        
//         vis[i][j]=1;
//         if(flag)
//         cnt++;
//         int x[]={-1,+1,0,0};
//         int y[]={0,0,-1,+1};
//         for(int k=0;k<4;k++){
//             dfs(i+x[k],j+y[k],cnt,flag,grid,vis);
//         }
//     }
    void mark(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int n=grid.size(),m=grid[0].size();
        
        if(i<0 || i==n || j<0 || j==m || grid[i][j]==0 || vis[i][j]){
            return;
        }
            
        // grid[i][j]=0;
        vis[i][j]=1;
        int x[]={-1,+1,0,0};
        int y[]={0,0,-1,+1};
        for(int k=0;k<4;k++){
            mark(i+x[k],j+y[k],grid,vis);
        }
    }
    void dfs(int i,int j,int &cnt,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int n=grid.size(),m=grid[0].size();
        
        if(i<0 || i==n || j<0 || j==m || grid[i][j]==0 || vis[i][j]){
            return;
        }
            
        vis[i][j]=1;
        ++cnt;
        // int cnt=0;
        int x[]={-1,+1,0,0};
        int y[]={0,0,-1,+1};
        for(int k=0;k<4;k++){
            dfs(i+x[k],j+y[k],cnt,grid,vis);
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0,mx=0,flag;
        
        for(int i=0;i<n;i++){
            if(grid[i][0] && !vis[i][0]){
                mark(i,0,grid,vis);
            }
            if(grid[i][m-1] && !vis[i][m-1]){
                mark(i,m-1,grid,vis);
            }
            
        }
        for(int i=0;i<m;i++){
            if(grid[0][i] && !vis[0][i]){
                mark(0,i,grid,vis);
            }
            if(grid[n-1][i]&& !vis[n-1][i]){
                mark(n-1,i,grid,vis);
            }
        }
         int ans=0;   
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 if(!vis[i][j] && grid[i][j]){
                    cnt=0;
                    dfs(i,j,cnt,grid,vis);
                    // mx=max(mx,cnt);
                     ans+=cnt;
                }
            }
        }
        return ans;
    }
};