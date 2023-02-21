class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0,rotten=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                    rotten++;
                }else if(grid[i][j]==1) fresh++;
            }
        }
        int cnt=0;
        if(fresh==0)
            return 0;
        if(rotten==0)
            return -1;
        
        
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int x=q.front().first,y=q.front().second;
                q.pop();
                if(x-1>=0 && !vis[x-1][y] && grid[x-1][y]==1){
                    q.push({x-1,y});
                    vis[x-1][y]=1;
                    grid[x-1][y]=2;
                }
                if(x+1<n && !vis[x+1][y] && grid[x+1][y]==1){
                    q.push({x+1,y});
                    vis[x+1][y]=1;
                    grid[x+1][y]=2;
                }
                if(y-1>=0 && !vis[x][y-1] && grid[x][y-1]==1){
                    q.push({x,y-1});
                    grid[x][y-1]=2;
                }
                if(y+1<m && !vis[x][y+1] && grid[x][y+1]==1){
                    q.push({x,y+1});
                    grid[x][y+1]=2;
                }
            }
            if(!q.empty())
              cnt++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                    return -1;
            }
        }
        return cnt;
    }
};