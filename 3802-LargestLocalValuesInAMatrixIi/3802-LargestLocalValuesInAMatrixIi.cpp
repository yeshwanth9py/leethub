// Last updated: 6/11/2026, 11:15:39 AM
class Solution {
public:
    vector<vector<vector<int>>> vec;
    int n;
    int m;
    int countLocalMaximums(vector<vector<int>>& arr) {
        n = arr.size();
        m = arr[0].size();

        vec.assign(n, vector<vector<int>>(m, vector<int>(201, 0)));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cur = arr[i][j];
                vec[i][j][cur]++;
                for(int k=0; k<=200; k++){
                    vec[i][j][k] += (i-1>=0?vec[i-1][j][k]:0);
                    vec[i][j][k] += (j-1>=0?vec[i][j-1][k]:0);
                    vec[i][j][k] -= ((i-1>=0 && j-1>=0)?vec[i-1][j-1][k]:0);
                }
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cur = arr[i][j];
                if(cur == 0) continue;

                int tot = 0;
                int br = min(i+cur, n-1);
                int tr = max(0, i-cur);
                int lc = max(0, j-cur);
                int rc = min(j+cur, m-1);
                
                for(int k=cur+1; k<=200; k++){
                    tot += vec[br][rc][k];
                    tot -= (tr-1>=0?vec[tr-1][rc][k]:0);
                    tot -= (lc-1>=0?vec[br][lc-1][k]:0);
                    tot += ((tr-1>=0 && lc-1>=0)?vec[tr-1][lc-1][k]:0);
                }

                if(br == i+cur && rc == j+cur) tot -= ((arr[br][rc]>cur)?1:0);
                if(tr == i-cur && rc == j+cur) tot -= ((arr[tr][rc]>cur)?1:0);
                if(tr == i-cur && lc == j-cur) tot -= ((arr[tr][lc]>cur)?1:0);
                if(br == i+cur && lc == j-cur) tot -= ((arr[br][lc]>cur)?1:0);

                if(tot == 0){
                    ans++;
                }
            }
        }

        return ans;
        
    }
};