// Last updated: 6/11/2026, 11:21:32 AM
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int el: nums){
            vector<int> temp;
            while(el){
                int ld = el%10;
                temp.push_back(ld);
                el = el/10;
            }
            reverse(temp.begin(), temp.end());
            for(int e: temp){
                ans.push_back(e);
            }
        }

        return ans;
    }
};