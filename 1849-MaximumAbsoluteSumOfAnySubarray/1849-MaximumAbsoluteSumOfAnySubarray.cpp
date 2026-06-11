// Last updated: 6/11/2026, 11:26:10 AM
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxpos = 0;
        int minpos = 0;
        int cursum1 = 0;
        int cursum2 = 0;
        for(int i=0; i<nums.size(); i++){
            cursum1 += nums[i];
            cursum2 += nums[i];
            if(cursum1<0){
                cursum1 = 0;
            }
            if(cursum2>0){
                cursum2 = 0;
            }
            maxpos = max(maxpos, cursum1);
            minpos = min(minpos, cursum2);
        }

        return max(maxpos, -minpos);

        // int minpos = 0;
        // cursum = 0;
        // for(int i=0; i<nums.size(); i++){
        //     cursum+=nums[i];
        //     if(cursum>0){
        //         cursum = 0;
        //     }
        //     minpos = min(minpos, cursum);
        // }

        // return max(maxpos, abs(minpos));

    }
};