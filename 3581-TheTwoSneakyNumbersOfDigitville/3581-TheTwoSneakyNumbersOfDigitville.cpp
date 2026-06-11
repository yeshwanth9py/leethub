// Last updated: 6/11/2026, 11:17:46 AM
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;
        for(int i=0; i<n; i++){
            xorr = xorr^nums[i];
        }

        for(int i=0; i<n-2; i++){
            xorr = xorr^i;
        }

        int diff = xorr&(-xorr);
        int a = 0;
        int b = 0;
        for(int el: nums){
            if((el&diff) == 0){
                a = a^(el);
            }else{
                b = b^el;
            }
        }

        for(int i=0; i<n-2; i++){
            if((i&diff) == 0){
                a = a^i;
            }else{
                b = b^i;
            }
        }


        return {a, b};

    }
};