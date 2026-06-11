// Last updated: 6/11/2026, 11:27:35 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int lo = 0;
        int ans = 0;
        deque<int> maxtn;
        deque<int> mintn;
        for(int ri=0; ri<nums.size(); ri++){
            while(!maxtn.empty() && maxtn.back()<nums[ri]){
                maxtn.pop_back();
            }
            maxtn.push_back(nums[ri]);

            while(!mintn.empty() && mintn.back()>nums[ri]){
                mintn.pop_back();
            }
            mintn.push_back(nums[ri]);


            while(maxtn.front() - mintn.front() > limit){
                if(nums[lo] == mintn.front()){
                    mintn.pop_front();
                    lo++;
                }
                else if(nums[lo] == maxtn.front()){
                    maxtn.pop_front();
                    lo++;
                }
                else{
                    lo++;
                }
            }

            ans = max(ans, ri-lo+1);
        }

        return ans;
    }
};