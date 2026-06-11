// Last updated: 6/11/2026, 11:30:47 AM
class Solution {
public:
    int n, m;
    bool check(int r, int c, vector<vector<int>> &arr){
        vector<int> vis(10, 0);
        if(r+3>n || c+3>m) return 0;

        set<int> st;
        for(int i=r; i<r+3; i++){
            int s = 0;
            for(int j=c; j<c+3; j++){
                // cout<<i<<" "<<j<<endl;
                if(arr[i][j]>=10 || arr[i][j]<=0) return 0;
                if(vis[arr[i][j]]) return 0;
                vis[arr[i][j]] = 1;
                s += arr[i][j];
            }
            st.insert(s);
            if(st.size()>1) return 0;
        }

        for(int i=c; i<c+3; i++){
            int s = 0;
            for(int j=r; j<r+3; j++){
                s += arr[j][i];
            }
            st.insert(s);
            if(st.size()>1) return 0;
        }

        int d1 = arr[r][c] + arr[r+2][c+2];
        int d2 = arr[r][c+2] + arr[r+2][c];

        return d1 == d2;
    }

    int numMagicSquaresInside(vector<vector<int>>& arr) {
        n = arr.size();
        m = arr[0].size();
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(check(i, j, arr)){
                    ans++;
                }
            }
        }

        return ans;
    }
};