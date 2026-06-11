// Last updated: 6/11/2026, 11:21:27 AM
class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int> ump;
        for(int i=0; i<n; i++){
            int el = nums[i];
            el = ((el%value+value)%value);
            ump[el]++;
        }
        for(int mx=0; mx<=n; mx++){
            int smx = (mx%value+value)%value;
            if(ump.find(smx) == ump.end() || ump[smx]<=0){
                return mx;
            }
            ump[smx]--;
        }

        return n+1;


    }
};