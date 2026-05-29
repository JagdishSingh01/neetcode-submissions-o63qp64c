class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (color == image[sr][sc]) return image;
        int oldColor = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        queue<pair<int, int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]== oldColor){
                    q.push({nrow, ncol});
                    image[nrow][ncol]=color;
                }
            }
        }
        return image;
    }
};