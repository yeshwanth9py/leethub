// Last updated: 6/11/2026, 11:29:51 AM
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n, 0);

        int op = 0;

        for(int i=0; i<n; i++){
            if(i) pref[i] = pref[i-1]^pref[i];

            int asal = pref[i]^nums[i];
            if(asal == 0){
                op++;
                if(i+k-1>=n) return -1;
                pref[i] ^= 1;
                if(i+k<n){
                    pref[i+k] ^= 1;
                }   
            }
        }

        return op;
    }
};