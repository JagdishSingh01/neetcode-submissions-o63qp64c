class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid , vector<vector<int>>& vis, int& cnt, int& mx){
        mx=max(mx,cnt);
        int m = grid.size()-1;
        int n = grid[0].size()-1;
        if(i>0 && grid[i-1][j]==1 && vis[i-1][j]==0){
            ++cnt;
            vis[i-1][j]=1;
            dfs(i-1, j, grid, vis, cnt, mx);
        }
        if(i<m && grid[i+1][j]==1 && vis[i+1][j]==0){
            ++cnt;
            vis[i+1][j]=1;
            dfs(i+1, j, grid, vis, cnt, mx);
        }
        if(j>0 && grid[i][j-1]==1 && vis[i][j-1]==0){
            ++cnt;
            vis[i][j-1]=1;
            dfs(i, j-1, grid, vis, cnt, mx);
        }
        if(j<n && grid[i][j+1]==1 && vis[i][j+1]==0){
            ++cnt;
            vis[i][j+1]=1;
            dfs(i, j+1, grid, vis, cnt, mx);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        
        int mx=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    int cnt=1;
                    vis[i][j]=1;
                    mx = max(mx,1);
                    dfs(i, j, grid,vis, cnt, mx);
                }
            }
        }
        return mx;
    }
};