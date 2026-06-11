// Last updated: 6/11/2026, 11:13:57 AM
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int, int> ump;
        for(int el: friends){
            ump[el] = 1;
        }

        vector<int> ans;
        for(int el: order){
            if(ump.find(el) != ump.end()){
                ans.push_back(el);
            }
        }

        return ans; 
    }
};