// Last updated: 6/11/2026, 11:31:37 AM
class Solution {
public:
    int newr[4] = {1, 0, -1, 0};
    int newc[4] = {0, 1, 0, -1};
    bool isvalid(int x, int y, int xr, int yc){
        if(x>=0 && x<xr && y>=0 && y<yc){
            return true;
        }
        return false;
    }

    void bfs(vector<vector<int>>& image, int x, int y, int oldc, int newcol){
        queue<pair<int, int>> q;
        q.push({x,y});
        image[x][y] = newcol;

        while(!q.empty()){
            auto cp = q.front();
            q.pop();
            image[cp.first][cp.second] = newcol;
            for(int i=0; i<4; i++){

                int nr = cp.first+newr[i];
                int nc = cp.second + newc[i];

                if(isvalid(nr, nc, image.size(), image[0].size()) && image[nr][nc]==oldc){
                    image[nr][nc] = newcol;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(color == image[sr][sc]){
            return image;
        }
        bfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};