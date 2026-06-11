// Last updated: 6/11/2026, 11:17:39 AM
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i=0; i<n; i++){
            if((nums[i]%2) == 0){
                ans.push_back(-1);
            }else{
                int j = 0;
                for(; j<=30; j++){
                    if((nums[i]&(1LL<<j)) == 0){
                        break;
                    }
                }
                j--;
                int v = (nums[i]^(1LL<<j));
                ans.push_back(v);
            }
        }

        return ans;
    }
};