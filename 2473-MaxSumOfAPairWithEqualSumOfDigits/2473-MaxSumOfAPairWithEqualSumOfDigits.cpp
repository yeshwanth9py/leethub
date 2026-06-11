// Last updated: 6/11/2026, 11:22:22 AM


class Solution {
public:
    int findsum(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n = n/10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> ump;
        int ans = -1;
        for(int el: nums){
            int cursum = findsum(el);
            if(ump.find(cursum)!=ump.end()){
                ans = max(ans, ump[cursum]+el);
            }
            ump[cursum] = max(ump[cursum], el);
        }

        return ans;
    }
};