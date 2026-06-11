// Last updated: 6/11/2026, 11:30:08 AM
class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s.size();
        int m = s[0].size();

        vector<int> maxe(m, 1);

        for(int i=m-2; i>=0; i--){
            for(int ni=i+1; ni<m; ni++){
                bool po = 1;
                for(int j=0; j<n; j++){
                    if(s[j][i]<=s[j][ni]){
                        continue;
                    }else{
                        po = 0;
                        break;
                    }
                }
                if(po){
                    maxe[i] = max(maxe[ni]+1, maxe[i]);
                }
            }
        }   
        
        int maxa = 0;
        for(int i=0; i<m; i++){
            maxa = max(maxa, maxe[i]);
        }

        return m-maxa;
    }
};