// Last updated: 6/11/2026, 11:11:19 AM
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=30; i>=0; i--){
            bool found = 0;
            int target = ans>>i;
            for(auto vec: grid){
                found = 0;
                for(int el: vec){
                    if(((el&(1LL<<i)) == 0) && (target | (el>>i)) == target){
                        found = 1;
                        break;
                    }
                }
                if(found == 0){
                    break;
                }
            }
            if(found == 0){
                ans |= (1LL<<i);
            }
        }
        return ans;
    }
};