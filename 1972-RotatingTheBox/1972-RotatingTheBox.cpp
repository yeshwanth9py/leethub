// Last updated: 6/11/2026, 11:25:42 AM
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        for(int i=0; i<n; i++){
            int j = 0;
            for(j=0; j<m;){
                if(arr[i][j] == '#'){
                    int cnt = 0;
                    int cur = j;
                    while(cur<m && (arr[i][cur] == '#' || arr[i][cur] == '.')){
                        if(arr[i][cur] == '#') cnt++;
                        arr[i][cur] = '.';
                        cur++;
                    }

                    j = cur;
                    cur--;
                    while(cnt>0){
                        arr[i][cur] = '#';
                        cur--;
                        cnt--;
                    }
                }else{
                    j++;
                }
            }
        }

        // return arr;

        vector<vector<char>> rot(m, vector<char>(n, 0));

        int sr = n-1;
        int sc = 0;
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                rot[i][j] = arr[sr][sc];
                sc++;
                if(sc==m){
                    sc = 0;
                    sr--;
                }
            }
        }

        return rot;

    }
};