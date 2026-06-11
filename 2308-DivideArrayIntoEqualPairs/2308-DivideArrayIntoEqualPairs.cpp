// Last updated: 6/11/2026, 11:23:17 AM
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int num: nums){
            ump[num]++;
        }
        int totrp = nums.size()/2;
        int totp = 0;
        for(auto el: ump){
            if((el.second%2) == 0){
                totp += (el.second/2);
            }
        }
        return totp==totrp;
    }
};