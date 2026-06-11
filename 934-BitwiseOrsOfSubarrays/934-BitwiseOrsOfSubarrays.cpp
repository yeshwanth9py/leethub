// Last updated: 6/11/2026, 11:30:25 AM
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> cur;
        unordered_set<int> next;
        for(int i=0; i<arr.size(); i++){
            next = {};
            next.insert(arr[i]);
            for(int el: cur){
                next.insert((el|arr[i]));
            }
            for(int el: next){
                ans.insert(el);
            }

            cur = next;
        }

        return ans.size();
    }
};