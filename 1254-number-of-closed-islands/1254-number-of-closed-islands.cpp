class Solution {
public:
    void transform(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n=grid.size(),m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j])
            return;
        vis[i][j]=1;
        grid[i][j]=1;
        transform(i,j-1,grid,vis);
        transform(i,j+1,grid,vis);
        transform(i-1,j,grid,vis);
        transform(i+1,j,grid,vis);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                transform(i,0,grid,vis);
            }
            if(grid[i][m-1]==0){
                transform(i,m-1,grid,vis);
            }
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0){
                transform(0,i,grid,vis);
            }
            if(grid[n-1][i]==0){
                transform(n-1,i,grid,vis);
            }
        }
        
        int cnt=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    transform(i,j,grid,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};