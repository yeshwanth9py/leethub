// Last updated: 6/11/2026, 11:30:00 AM
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int n = nums.size();
        int cs = 0;
        ump[0] = 1;
        int cnt = 0;
        for(int i=0; i<n; i++){
            cs += nums[i];
            if(cs<0){
                cs = (cs%k+k)%k;
            }else{
                cs = cs%k;
            }
            if(ump.find(cs)!=ump.end()){
                cnt += ump[cs];
            }
            ump[cs]++;
        }

        return cnt;
    }
};