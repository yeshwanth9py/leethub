// Last updated: 6/11/2026, 11:31:03 AM
class Solution {
public:
    int po;
    double dp[101][101];
    double arr[101][101];
    double rec(int r, int c){
        if(c>r) return 0;
        if(c<0 || r<0) return 0;
        if(r == 0){
            arr[r][c] = po;
            if(po>1){
                arr[r][c] = 1;
            }
            double rem = po-1;
            if(rem<0) return 0;
            return (rem*1.0)/2;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        arr[r][c] = rec(r-1, c) + rec(r-1, c-1);
        double rem = 0;
        if(arr[r][c]>1){
            rem = arr[r][c]-1;
            arr[r][c] = 1;
        }
        return dp[r][c] = (rem*1.0)/2;
    }

    double champagneTower(int p, int qr, int qg) {
        po = p;
        for(int i=0; i<=qr; i++){
            for(int j=0; j<=qr; j++){
                dp[i][j] = -1;
            }
        }
        rec(qr, qg);
        return arr[qr][qg];
    }
};