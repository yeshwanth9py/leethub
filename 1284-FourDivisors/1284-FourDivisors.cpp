// Last updated: 6/11/2026, 11:29:05 AM
class Solution {
public:
    int findivsum(int x){
        if(x == 1) return 0;
        int cnt = 2;
        int s = 1+x;
        for(int i=2; i*i<=x; i++){
            if(x%i == 0){
                cnt++;
                s +=i;
                if(x/i != i){
                    cnt++;
                    s += (x/i);
                }
            }
        }

        if(cnt==4) return s;
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int ts = 0;
        // cout<<findivsum(21)<<" ";
        for(int el: nums){
            ts += findivsum(el);
        }

        return ts;
    }
};