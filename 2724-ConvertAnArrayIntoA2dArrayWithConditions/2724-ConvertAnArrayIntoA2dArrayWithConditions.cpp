// Last updated: 6/11/2026, 11:21:02 AM
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int i=0; i<nums.size(); i++){
            ump[nums[i]]++;
        }
        vector<vector<int>> ans;
        while(!ump.empty()){
            vector<int> temp;
            vector<int> keystoerase;
            for(auto el: ump){
                temp.push_back(el.first);
                ump[el.first]--;

                if(ump[el.first] == 0){
                    keystoerase.push_back(el.first);
                }
            }
            for(auto el: keystoerase){
                ump.erase(el);
            }
            keystoerase = {};
            ans.push_back(temp);
        }

        return ans;
    }
};