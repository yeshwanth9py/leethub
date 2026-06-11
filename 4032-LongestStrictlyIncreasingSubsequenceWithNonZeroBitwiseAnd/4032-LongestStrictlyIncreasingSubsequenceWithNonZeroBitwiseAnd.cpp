// Last updated: 6/11/2026, 11:13:43 AM
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;
        for(int i=0; i<31; i++){
            vector<int> sub;
            for(int el: nums){
                if((el&(1LL<<i)) != 0){
                    if(sub.size() == 0 || sub.back()<el){
                        sub.push_back(el);
                    }else{
                        int ind = lower_bound(sub.begin(), sub.end(), el)-sub.begin();
                        sub[ind] = el;
                    }
                }
            }
           
            ans = max(ans, (int) sub.size());
        }
        return ans;
    }
};