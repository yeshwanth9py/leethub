// Last updated: 6/11/2026, 11:17:35 AM
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if((nums[i]&1)!=1){
                ans.push_back(-1);
            }else{
                int j=0;
                for(; j<=30; j++){
                    if((nums[i]&(1LL<<j))==0){
                        break;
                    }
                }
                int cur = (nums[i]^(1LL<<(j-1)));
                ans.push_back(cur);
            }
        }

        return ans;
    }
};