class Solution {
public:
    void nonSurrounded(int r, int c,vector<vector<char>>& board, vector<vector<int>>& vis, queue<pair<int,int>>& nq){
        int m= board.size();
        int n= board[0].size();
        vis[r][c]=1;
        nq.push({r,c});

        if(r>0 && !vis[r-1][c]){
            nonSurrounded(r-1, c, board, vis, nq);
        }
        if(r+1<m && !vis[r+1][c]){
            nonSurrounded(r+1, c, board, vis, nq);
        }
        if(c>0 && !vis[r][c-1]){
            nonSurrounded(r, c-1, board, vis, nq);
        }
        if(c+1<n && !vis[r][c+1]){
            nonSurrounded(r, c+1, board, vis, nq);
        }  
    }

    void solve(vector<vector<char>>& board) {
        int m= board.size();
        int n= board[0].size();
        queue<pair<int, int>>q;
        vector<vector<int>>vis(m, vector<int>(n,0));

        //put all non surrounded 0s in the queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='O'){
                    if(i == 0 || i == m-1 || j == 0 || j == n-1) q.push({i,j});
                }else{
                    vis[i][j]=1;
                }
            }
        }

        //new queue of non surrounded 0s on traversing
        queue<pair<int,int>>nq;

        //now checking for non surrounded 0 chain
        while(!q.empty()){
            int row= q.front().first;
            int col = q.front().second;
            q.pop();
            if(!vis[row][col]) nonSurrounded(row, col, board, vis, nq);
        }

        board = vector<vector<char>>(m, vector<char>(n,'X'));
        
        //changing the 'X' back to the non surrounded 0s from the new queue 'nq'
        while(!nq.empty()){
            int row= nq.front().first;
            int col = nq.front().second;
            nq.pop();
            board[row][col]='O';
        }
      
    }
};