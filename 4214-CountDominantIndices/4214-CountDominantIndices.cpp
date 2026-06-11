// Last updated: 6/11/2026, 11:10:32 AM
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n, 0);
        suff[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suff[i] = suff[i+1]+nums[i];
        }

        int ans = 0;
        for(int i=0; i<n-1; i++){
            int v = nums[i];
            int ns = suff[i+1];
            double avg = (1.0*ns)/(n-i-1);
            // cout<<i<<" "<<avg<<endl;
            if(v>avg){
                ans++;
            }
        }

        return ans;
    }
};