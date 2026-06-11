// Last updated: 6/11/2026, 11:38:02 AM
class Solution {
public:
    vector<vector<int>> ans;
    void rec(int ind, vector<int> temp, vector<int>& candidates, int target){
        if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
                return;
            }
            return;
        }
        if(target<0) return;
        temp.push_back(candidates[ind]);
        rec(ind, temp, candidates, target-candidates[ind]);
        temp.pop_back();
        rec(ind+1, temp,candidates, target);
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<int> temp;
        rec(0, temp, candidates, target);
        return ans;
    }
};