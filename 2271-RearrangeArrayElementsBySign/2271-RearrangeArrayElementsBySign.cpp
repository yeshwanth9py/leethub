// Last updated: 6/11/2026, 11:23:32 AM
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> pos, neg;
        for(int e: nums){
            if(e>0){
                pos.push(e);
            }else{
                neg.push(e);
            }
        }

        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            if(i%2 == 0){
                int el = pos.front(); pos.pop();
                ans.push_back(el);
            }else{
                int el = neg.front(); neg.pop();
                ans.push_back(el);
            }
        }
        return ans;
    }
};