// Last updated: 6/11/2026, 11:15:01 AM
class Solution {
public:
    int sum(int num){
        int ts = 0;
        while(num){
            ts += num%10;
            num = num/10;
        }
        return ts;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(sum(nums[i]) == i){
                return i;
            }
        }
        return -1;
    }
};