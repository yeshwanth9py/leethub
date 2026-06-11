// Last updated: 6/11/2026, 11:37:41 AM
class Solution {
public:

    vector<vector<string>> ans;
    bool isplacable(int r, int c, vector<string> &board){
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size()){
            return false;
        }

        int dr = r;
        int dc = c;

        while(dr>=0 && dc>=0){
            if(board[dr][dc]!='Q'){
                dr--;
                dc--;
            }else{
                return false;
            }
        }

        dr = r;
        dc = c;
        while(dr>=0 && dc>=0){
            if(board[dr][dc]!='Q'){
                dr--;
            }else{
                return false;
            }
        }

        dr = r;
        dc = c;

        while(dr>=0 && dc<board.size()){
            if(board[dr][dc]!='Q'){
                dr--;
                dc++;
            }else{
                return false;
            }
        }

        return true;
    }


    void rec(int ind, vector<string> &board){
        if(ind == board.size()){
            ans.push_back(board);
            // return true;
            return;
        }
        int n = board.size();
        for(int i=0; i<n; i++){
            if(board[ind][i] == '.'){
                if(isplacable(ind, i, board)){
                    board[ind][i] = 'Q';
                    rec(ind+1, board);
                    board[ind][i] = '.';
                }
            }
        }

        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n, '.'));
        ans.clear();
        rec(0, board);
        return ans;
    }
};