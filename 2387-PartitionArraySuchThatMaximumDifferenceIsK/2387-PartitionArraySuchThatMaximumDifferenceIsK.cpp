// Last updated: 6/11/2026, 11:22:58 AM
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {

        int me = *(max_element(nums.begin(), nums.end()));
        
        vector<int> freq(me+1, 0);

        for(int i=0; i<nums.size(); i++){
            freq[nums[i]]++;
        }

        int nos = 0;
        int fe = 1e9;

        for(int i=0; i<=me; i++){
            if(freq[i] == 0) continue;
            if(fe == 1e9){
                nos = 1;
                fe = i;
            }else{
                if(i-fe<=k){
                    continue;
                }else{
                    nos++;
                    fe = i;
                }
            }
        }

        return nos;

    }
};