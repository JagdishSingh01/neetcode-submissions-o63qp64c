class Solution {
public:
    void nonSurrounded(int r, int c,vector<vector<int>>& grid, vector<vector<int>>& vis){
        int m= grid.size();
        int n= grid[0].size();
        vis[r][c]=1;

        if(r>0 && !vis[r-1][c]){
            nonSurrounded(r-1, c, grid, vis);
        }
        if(r+1<m && !vis[r+1][c]){
            nonSurrounded(r+1, c, grid, vis);
        }
        if(c>0 && !vis[r][c-1]){
            nonSurrounded(r, c-1, grid, vis);
        }
        if(c+1<n && !vis[r][c+1]){
            nonSurrounded(r, c+1, grid, vis);
        }  
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>vis(m, vector<int>(n,0));

        //put all non surrounded 1s in the queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    if(i == 0 || i == m-1 || j == 0 || j == n-1) q.push({i,j});
                }else{
                    vis[i][j]=1;
                }
            }
        }

        //now checking for non surrounded 1 chain
        while(!q.empty()){
            int row= q.front().first;
            int col = q.front().second;
            q.pop();
            if(!vis[row][col]) nonSurrounded(row, col, grid, vis);
        }
        int encl=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(vis[i][j]==0){
                    encl++;
                }
            }
        }
        return encl;
    }
};