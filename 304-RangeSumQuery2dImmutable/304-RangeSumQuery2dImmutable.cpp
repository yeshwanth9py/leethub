// Last updated: 6/11/2026, 11:33:55 AM
class NumMatrix {
public:
    vector<vector<int>> prefix;
    vector<vector<int>> arr;
    int n;
    int m;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        arr = matrix;
        prefix.clear();
        prefix.resize(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                prefix[i][j] = ((j-1>=0)?prefix[i][j-1]:0)+((i-1>=0)?prefix[i-1][j]:0)- ((i-1>=0 && j-1>=0)?prefix[i-1][j-1]:0) + arr[i][j];
            }
        }



    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int curs = prefix[row2][col2] - ((row1-1>=0)?prefix[row1-1][col2]:0) - ((col1-1>=0)?prefix[row2][col1-1]:0) + ((row1-1>=0 && col1-1>=0)?prefix[row1-1][col1-1]:0);
        return curs;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */