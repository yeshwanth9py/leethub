// Last updated: 6/11/2026, 11:28:52 AM
class Solution {
public:
    int n, m;
    bool isgood(int r, int c, int md, vector<vector<int>> &grid){
        if(r+md>n || c+md>m) return 0;

        int k1 = r-c;
        int k2 = (c+md-1) + r;
        set<int> sums;
        int ds1 = 0;
        int ds2 = 0;

        for(int i=r; i<r+md; i++){
            int s = 0;
            for(int j=c; j<c+md; j++){
                s += grid[i][j];
                if(i - j == k1){
                    ds1 += grid[i][j];
                }
                if(i+j == k2){
                    ds2 += grid[i][j];
                }   
            }
            sums.insert(s);
            if(sums.size()>1) return 0;
        }

        sums.insert(ds1);
        sums.insert(ds2);
        if(sums.size()>1) return 0;

        for(int j=c; j<c+md; j++){
            int s = 0;
            for(int i=r; i<r+md; i++){
                s += grid[i][j];
            }
            sums.insert(s);
        }

        if(sums.size()>1) return 0;
        return 1;
    }


    bool check(int md, vector<vector<int>> &grid){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isgood(i, j, md, grid)) return 1;
            }
        }
        return 0;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        
        int mid = min(m, n);
        while(mid>1){
            if(check(mid, grid)){
                return mid;
            }else{
                mid--;
            }
        }

        return 1;

    }
};