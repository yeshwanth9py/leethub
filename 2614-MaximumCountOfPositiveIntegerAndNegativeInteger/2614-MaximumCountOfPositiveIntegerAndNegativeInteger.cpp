// Last updated: 6/11/2026, 11:21:38 AM
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        for(int el: nums){
            if(el>0){
                pos++;
            }else if(el<0){
                neg++;
            }
        }

        return max(pos, neg);
    }
};