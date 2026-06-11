// Last updated: 6/11/2026, 11:17:43 AM
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> ump;
        int n = nums.size();
        int totsum = 0;
        for(int i=0; i<n; i++){
            ump[nums[i]]++;
            totsum += nums[i];
        }
        int out = -1e9;

        for(int i=0; i<n; i++){
            totsum -= nums[i];
            ump[nums[i]]--;
            if(ump[nums[i]] == 0){
                ump.erase(nums[i]);
            }
            if(totsum%2 == 0){
                if(ump.find(totsum/2)!=ump.end()){
                    out = max(out, nums[i]);
                }
            }
            ump[nums[i]]++;
            totsum += nums[i];
        } 
        return out;

    }
};