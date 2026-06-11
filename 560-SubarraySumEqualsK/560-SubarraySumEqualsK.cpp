// Last updated: 6/11/2026, 11:32:30 AM
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> ump;
        int ps = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            ps += nums[i];
            if(ps == k){
                ans++;
            }
            if(ump.find(ps-k)!=ump.end()){
                ans += ump[ps-k];
            }
            ump[ps]++;
        }

        return ans;
    }
};