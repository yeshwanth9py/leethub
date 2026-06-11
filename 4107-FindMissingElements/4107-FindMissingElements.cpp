// Last updated: 6/11/2026, 11:12:38 AM
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int lo = nums[0];
        int hi = nums.back();

        unordered_map<int, int> ump;
        for(int el: nums){
            ump[el] = 1;
        }
        vector<int> miss;
        for(int i=lo+1; i<hi; i++){
            if(ump.find(i) == ump.end() || ump[i] == 0){
                miss.push_back(i);
            }
        }
        

        
        return miss;
        
    }
};