// Last updated: 6/11/2026, 11:32:48 AM
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int n = nums.size();
        int cs = 0;
        ump[0] = -1;
        for(int i=0; i<n; i++){
            cs += nums[i];
            cs %= k;
            if(ump.find(cs)!=ump.end()){
                if(i-ump[cs]>=2) return 1;
            }else{
                ump[cs] = i;
            }
        }
        return 0;
    }
};