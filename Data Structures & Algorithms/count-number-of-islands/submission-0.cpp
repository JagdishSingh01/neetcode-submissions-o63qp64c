class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis,vector<vector<char>>& grid){
        if(grid[i][j]=='0') return ;
        int m = grid.size();
        int n = grid[0].size();
        
        if (i > 0 && grid[i - 1][j] == '1' && !vis[i-1][j]) {
            vis[i-1][j]=1;
          
            dfs(i-1, j, vis, grid);
        }

        if (i + 1<m && grid[i + 1][j] == '1' && !vis[i+1][j]) {
            vis[i+1][j]=1;
              
            dfs(i+1, j, vis, grid);
        }

        if (j > 0 && grid[i][j - 1] == '1' && !vis[i][j-1]) {
            vis[i][j-1]=1;
             
            dfs(i, j-1, vis, grid);
        }

        if (j + 1 < n && grid[i][j + 1] == '1' && !vis[i][j+1]) {
            vis[i][j+1]=1;
             
            dfs(i, j+1, vis, grid);
        }
        
        
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island=0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        
        for(int i =0 ; i<m; i++){
            for(int j=0; j<n ; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    vis[i][j]=1;
                    dfs(i, j, vis, grid);
                    island++;
                }
            }
        }
    
        
        return island;
    
        
    }
};
