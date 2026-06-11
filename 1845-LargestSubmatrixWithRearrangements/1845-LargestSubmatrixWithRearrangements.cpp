// Last updated: 6/11/2026, 11:26:12 AM
class Solution {
public:
    int n;
    int m;

    int findmaxhist(vector<int> temp){
        sort(temp.begin(), temp.end());
        int tot = temp.size();
        int ans = 0;
        for(int i=0; i<temp.size(); i++){
            int cura = temp[i]*(temp.size()-i);
            ans = max(ans, cura);
        }
        return ans;
    }

    int largestSubmatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();

        vector<int> temp(m, 0);
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 1){
                    temp[j] += 1;
                }else{
                    temp[j] = 0;
                }
            }
            ans = max(ans, findmaxhist(temp));
        }

        return ans;

    }
};