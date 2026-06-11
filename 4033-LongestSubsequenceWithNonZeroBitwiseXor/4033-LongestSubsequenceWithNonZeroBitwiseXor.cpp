// Last updated: 6/11/2026, 11:13:42 AM
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int v = 0;
        int nz = 0;
        int z = 0;
        for(int el: nums){
            v ^= el;
            if(el != 0){
                nz++;
            }else{
                z++;
            }
        }
        if(v != 0){
            return nums.size();
        }
        if(nz>0) return nz-1+z;
        return 0;
        
        
    }
};