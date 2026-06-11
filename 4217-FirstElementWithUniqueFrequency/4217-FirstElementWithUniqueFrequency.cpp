// Last updated: 6/11/2026, 11:10:28 AM
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1, 0);
        unordered_map<int, int> ump;
        for(int i=0; i<n; i++){
            ump[nums[i]]++;
        }

        for(auto el: ump){
            int f = el.second;
            freq[f]++;
        }

        for(int i=0; i<n; i++){
            int el = nums[i];
            if(freq[ump[el]] == 1){
                return el;
            }
        }

        return -1;
        
    }
};