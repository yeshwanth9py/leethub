// Last updated: 6/11/2026, 11:37:05 AM
class Solution {
public:
    bool rec(int r, int c, int ind, string word, vector<vector<char>>& board){
        if(ind >= word.size()){
            return true;
        }

        if(r<0 || r>=board.size() || c<0 || c>=board[0].size()){
            return false;
        }
        

        if(word[ind] == board[r][c]){
            char temp = board[r][c];
            board[r][c] = '-';
            if(rec(r+1, c, ind+1, word, board) || rec(r, c+1, ind+1, word, board) || rec(r-1, c, ind+1, word, board) || rec(r, c-1, ind+1, word, board)){
                return true;
            }
            board[r][c] = temp;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();


        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(board[i][j] == word[0]){
                    if(rec(i, j, 0, word, board)){
                        cout<<"hh"<<endl;
                        return true;
                    }
                }
            }
        }

        return false;
    }
};