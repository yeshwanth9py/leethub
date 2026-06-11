// Last updated: 6/11/2026, 11:17:38 AM
class Solution {
public:
    int minElement(vector<int>& nums) {
        int minel = 1e9;
        for(int el: nums){
            int cs = 0;
            while(el){
                int ld = el%10; 
                cs += ld;
                el = el/10;
            }

            minel = min(minel, cs);
        }

        return minel;
    }
};