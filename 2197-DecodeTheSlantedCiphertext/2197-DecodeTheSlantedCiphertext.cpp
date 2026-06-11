// Last updated: 6/11/2026, 11:24:11 AM
class Solution {
public:
    string decodeCiphertext(string et, int r) {
        int c = et.size()/r;
        vector<vector<char>> ans(r, vector<char>(c, '-'));
        int st = 0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                ans[i][j] = et[st];
                st++;
            }
        }

        string anss = "";
        int stj = 0;
        int i = 0;
        int j = 0;
        while(j<c){
            char cur = ans[i][j];
            anss += cur;
            i++;
            j++;
            if(i>=r || j>=c){
                i = 0;
                j = stj+1;
                stj++;
            }
        }
        while(anss.size()>0 && anss.back() == ' ') anss.pop_back();
        return anss;
    }
};