// Last updated: 6/11/2026, 11:12:32 AM
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ump;
        vector<int> next(n, -1);
        for(int i=n-1; i>=0; i--){
            if(ump.find(nums[i]) != ump.end()){
                next[i] = ump[nums[i]];
            }
            ump[nums[i]] = i;
        }

        vector<int> prev(n, -1);
        ump.clear();
        for(int i=0; i<n; i++){
            if(ump.find(nums[i]) != ump.end()){
                prev[i] = ump[nums[i]];
            }
            ump[nums[i]] = i;
        }

        int ans = 1e9;
        for(int i=0; i<n; i++){
            int pr = prev[i];
            int nex = next[i];
            if(pr != -1 && nex != -1){
                ans = min(ans, abs(pr-i) + abs(nex-i) + abs(nex-pr));
            }
        }
        if(ans == 1e9) return -1;
        return ans;
    }
};