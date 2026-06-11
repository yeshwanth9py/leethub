// Last updated: 6/11/2026, 11:32:58 AM
class Solution {
public:
    int bitset[32];
    const int mod = 1e9+7;
    int totalHammingDistance(vector<int>& nums) {
        memset(bitset, 0, sizeof(bitset));
        int n = nums.size();

        int ans = 0;
        for(int i=0; i<n; i++){
            int el = nums[i];

            for(int j=0; j<32; j++){
                if((el&(1<<j)) == 0){
                    ans += bitset[j];
                }else{
                    ans += (i-bitset[j]);
                }
            }

            for(int j=0; j<32; j++){
                if((el&(1<<j)) != 0){
                    bitset[j]++;
                }
            }
        }

        return ans;


    }
};