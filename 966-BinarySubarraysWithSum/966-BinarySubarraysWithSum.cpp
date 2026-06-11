// Last updated: 6/11/2026, 11:30:17 AM
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pref(n, 0);
        for(int i=0; i<n; i++){
            pref[i] = ((i-1>=0)?pref[i-1]:0)+nums[i];
        }
        unordered_map<int, int> ump;
        int cnt = 0;
        ump[0] = 1;
        for(int i=0; i<n; i++){
            if(ump.find(pref[i]-goal)!=ump.end()){
                cnt += ump[pref[i]-goal];
            }
            ump[pref[i]]++;
        }
        return cnt;
    }
};