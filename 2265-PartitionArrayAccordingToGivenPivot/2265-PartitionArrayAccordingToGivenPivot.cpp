// Last updated: 6/11/2026, 11:23:36 AM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pi) {
        vector<int> prev;
        vector<int> next;
        int cnt = 0;
        for(int el: nums){
            if(el<pi){
                prev.push_back(el);
            }else if(el == pi){
                cnt++;
            }else{
                next.push_back(el);
            }
        }
        vector<int> ans;
        for(int el: prev){
            ans.push_back(el);
        }
        while(cnt--){
            ans.push_back(pi);
        }
        for(int el: next){
            ans.push_back(el);
        }

        return ans;
    }
};