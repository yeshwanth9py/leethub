// Last updated: 6/11/2026, 11:10:21 AM
class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int f = 0;
        int s = 0;
        int a = 1;
        
        int gn = -1;
        for(int i=0; i<nums.size(); i++){
            gn++;
            if((nums[i]%2) == 1){
                a = !a;
            }
            if(gn == 5){
                a = !a;
                gn = -1;
            }
            if(a == 1){
                f += nums[i];
            }else{
                s += nums[i];
            }
        }
        return f-s;
    }
};