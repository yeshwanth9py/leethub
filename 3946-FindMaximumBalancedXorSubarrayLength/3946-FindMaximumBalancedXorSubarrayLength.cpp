// Last updated: 6/11/2026, 11:14:36 AM
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
        int ans = 0;
        map<pair<int, int>, int> mp;
        //e = 1, o = -1, cp = e+o, cx = prefxor
        int cp = 0;
        int curx = 0;
        for(int i=0; i<n; i++){
            if(nums[i]%2 == 0){
                cp++;
            }else{
                cp--;
            }
            curx ^= nums[i];
            // cout<<curx<<" "<<cp<<endl;
            if(curx == 0 && cp == 0){
                ans = max(ans, i+1);
            }

            if(mp.find({curx, cp})!=mp.end()){
                ans = max(ans, i-mp[{curx, cp}]);
            }
            if(mp.find({curx, cp})==mp.end()) mp[{curx, cp}] = i;
        }
        return ans;
    }
};