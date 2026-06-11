// Last updated: 6/11/2026, 11:28:41 AM
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int cursum = 0;
        unordered_map<int, int> ump;
        ump[0] = 1;
        int ans = 0;
        for(int i=0; i<n; i++){
            cursum += (nums[i]%2 == 1);
            if(ump.find(cursum-k)!=ump.end()){
                ans += ump[cursum-k];
            }
            ump[cursum]++;
        }
        return ans;
    }
};