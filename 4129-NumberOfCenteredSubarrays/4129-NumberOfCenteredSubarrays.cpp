// Last updated: 6/11/2026, 11:12:17 AM
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            set<int> els;
            int sm = 0;
            // vector<int> sub;
            for(int j=i; j<nums.size(); j++){
                sm += nums[j];
                els.insert(nums[j]);
                if(els.find(sm)!=els.end()){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};