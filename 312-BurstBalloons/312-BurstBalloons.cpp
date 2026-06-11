// Last updated: 6/11/2026, 11:33:51 AM
class Solution {
public:
    vector<int> nums;
    int dp[305][305];
    int rec(int st, int en){
        if(en == st+1){
            return 0;
        }
        if(dp[st][en]!=-1) return dp[st][en];
        int maxcost = -1e9;
        for(int ch=st+1; ch<en; ch++){
            int curcost = nums[st]*nums[ch]*nums[en] + rec(st, ch)+ rec(ch, en);
            maxcost = max(maxcost, curcost);
        }

        return dp[st][en] = maxcost;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        this->nums = nums;

        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                dp[i][j] = -1;
            }
        }

        return rec(0, n-1);
    }
};