// Last updated: 6/11/2026, 11:20:55 AM
class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& que) {
        vector<int> mycol(n, 0);
        vector<int> ans;
        
        int cur = 0;
        for(auto el: que){
            int ind = el[0];
            int co = el[1];
            if(mycol[ind] == 0){
                mycol[ind] = co;
                if(ind-1>=0 && mycol[ind-1] == mycol[ind]){
                    cur++;
                }
                if(ind+1<n && mycol[ind+1] == mycol[ind]){
                    cur++;
                }
            }else{
                if(ind-1>=0 && mycol[ind-1] == mycol[ind]){
                    cur--;
                }
                if(ind+1<n && mycol[ind+1] == mycol[ind]){
                    cur--;
                }

                mycol[ind] = co;
                
                if(ind-1>=0 && mycol[ind-1] == mycol[ind]){
                    cur++;
                }
                if(ind+1<n && mycol[ind+1] == mycol[ind]){
                    cur++;
                }
            }

            ans.push_back(cur);
        }

        return ans;
    }
};