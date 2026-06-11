// Last updated: 6/11/2026, 11:23:31 AM
class Solution {
public:
    int findFinalValue(vector<int>& nums, int x) {
        unordered_set<int> us;
        for(int el: nums) us.insert(el);
        while(1){
            if(us.find(x)!=us.end()){
                x = 2*x;
            }else{
                return x;
            }
        }
        return 0;
    }
};