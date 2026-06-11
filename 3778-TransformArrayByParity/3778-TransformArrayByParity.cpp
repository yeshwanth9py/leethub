// Last updated: 6/11/2026, 11:16:01 AM
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size();
        int o = 0;
        int e = 0;
        for(int i=0; i<n; i++){
            if(nums[i]&1){
                o++;
            }else{
                e++;
            }
        }

        vector<int> ans;
        for(int i=0; i<e; i++){
            ans.push_back(0);
        }
        for(int i=0; i<o; i++){
            ans.push_back(1);
        }

        return ans;
    }
};