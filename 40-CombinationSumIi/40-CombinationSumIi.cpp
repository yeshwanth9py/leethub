// Last updated: 6/11/2026, 11:37:59 AM
class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int>& candidates, int ind, vector<int> &temp, int target){
        // if(ind == candidates.size()){
            if(target == 0){
                ans.push_back(temp);
            }
            // return;
        // }
        if(target<0) return;
        for(int i=ind; i<candidates.size(); i++){
            if(i>ind && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[i]>target){
                break;
            }
            temp.push_back(candidates[i]);
            rec(candidates, i+1, temp, target-candidates[i]);
            temp.pop_back();
            // rec(candidates, i+1, temp, target);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        rec(candidates, 0, temp, target);
        return ans;
    }
};