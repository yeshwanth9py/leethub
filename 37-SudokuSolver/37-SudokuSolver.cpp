// Last updated: 6/11/2026, 11:38:06 AM
class Solution {
public:
    int n;
    int m;
    bool isvalid(int r, int c, int val, vector<vector<char>>& arr){
        int dr = n-1;
        int dc = c;
        while(dr>=0){
            if((arr[dr][dc]-'0') == val){
                return 0;
            }
            dr--;
        }

        dr = r;
        dc = m-1;
        while(dc>=0){
            if((arr[dr][dc]-'0') == val){
                return 0;
            }
            dc--;
        }

        int gr = (r/3)*3;
        int gc = (c/3)*3;

        for(int i=gr; i<gr+3; i++){
            for(int j=gc; j<gc+3; j++){
                if((arr[i][j]-'0') == val) return 0;
            }
        }

        return 1;
    }

    bool rec(int r, int c, vector<vector<char>> &arr){
        if(r<0 || r>n || c<0 || c>m) return 0;
        if(c == m){
            r++;
            c = 0;
        }
        if(r == n){
            // for(int i=0; i<n; i++){
            //     for(int j=0; j<m; j++){
            //         cout<<arr[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            return 1;
        }

        if(arr[r][c] != '.'){
            return rec(r, c+1, arr);
        }

        for(int i=1; i<=9; i++){
            if(isvalid(r, c, i, arr)){
                arr[r][c] = char(i+'0');
                if(rec(r, c+1, arr)) return 1;
                arr[r][c] = '.';
            }
        }
        return 0;
    }


    void solveSudoku(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        rec(0, 0, board);
    }
};