// Last updated: 6/11/2026, 11:21:43 AM
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int prev = -1;
        int n = forts.size();
        int res = 0;
        for(int i=0; i<n; i++){
            if(forts[i]==-1 || forts[i] == 1){
                if(prev!=-1 && forts[i]!=forts[prev]){
                    res = max(res, i-prev-1);
                }
                prev = i;
            }
        }

        return res;
    }
};