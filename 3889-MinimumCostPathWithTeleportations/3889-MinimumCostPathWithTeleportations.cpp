// Last updated: 6/11/2026, 11:14:51 AM
class Solution {
public:
    int n, m;
    vector<vector<int>> arr;
    int k;
    int dp[81][81][11];
    int rec(){
        // if(rem<0) return 1e9;
        // if(r == n-1 && c == m-1){
        //     return 0;
        // }

        // int right = 1e9;
        // if(c+1<m){
        //     right = arr[r][c+1] + rec(r, c+1, rem);
        // }

        // int down = 1e9;
        // if(r+1<n){
        //     down = arr[r+1][c] + rec(r+1, c, rem);
        // }

        // if(rem>0){
        //     for(int i=0; i<n; i++){
        //         for(int j=0; j<m; j++){
        //             if(arr[i][j]<=arr[r][c]){
        //                 down = min(down, rec(i, j, rem-1));
        //             }
        //         }
        //     }
        // }

        // return min(right, down);

        vector<pair<int, int>> prev;
        for(int rem=0; rem<=k; rem++){
            sort(prev.begin(), prev.end());
            int mtn = 1e9;
            for(int i=0; i<prev.size(); i++){
                int cv = min(mtn, prev[i].second);
                prev[i].second = cv;
                mtn = cv;
            }

            vector<pair<int, int>> next;
            for(int r=n-1; r>=0; r--){
                for(int c=m-1; c>=0; c--){
                    if(r == n-1 && c == m-1){
                        dp[r][c][rem] = 0;
                        next.push_back({arr[r][c], dp[r][c][rem]});
                        continue;
                    }

                    int right = 1e9;
                    if(c+1<m){
                        right = arr[r][c+1] + dp[r][c+1][rem];
                    }

                    int down = 1e9;
                    if(r+1<n){
                        down = arr[r+1][c] + dp[r+1][c][rem];
                    }
                   
                    if(rem>0){
                        // for(int i=0; i<n; i++){
                        //     for(int j=0; j<m; j++){
                        //         if(arr[i][j]<=arr[r][c]){
                        //             down = min(down, dp[i][j][rem-1]);
                        //         }
                        //     }
                        // }
                        auto it = upper_bound(prev.begin(), prev.end(), make_pair(arr[r][c], 1e9));
                        if(it != prev.begin()){
                            it--;
                            down = min(down, (*it).second);
                        }
                    }

                    dp[r][c][rem] = min(right, down);
                    next.push_back({arr[r][c], dp[r][c][rem]});
                }
            }
            swap(prev, next);
        }

        return dp[0][0][k];
    }

    int minCost(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        this->k = k;
        arr = grid;

        return rec();
    }
};