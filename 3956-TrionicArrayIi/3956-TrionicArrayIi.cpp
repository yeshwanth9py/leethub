// Last updated: 6/11/2026, 11:14:28 AM
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> inctill(n, 0);
        vector<long long> prefs(n, 0);
        prefs[0] = nums[0];
        for(long long i=1; i<n; i++){
            prefs[i] = prefs[i-1] + nums[i];
        }

        for(long long i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                inctill[i] = inctill[i+1]+1;
            }
        }
        vector<long long> dectill(n, 0);
        for(long long i=n-2; i>=0; i--){
            if(nums[i]>nums[i+1]){
                dectill[i] = dectill[i+1]+1;
            }
        }
        long long ans = -1e18;
        for(long long i=0; i<n; i++){
            long long curs = 0;
            if(inctill[i] == 0) continue;
            long long idx = inctill[i]+i;
            if(idx>=n) continue;
            curs += prefs[idx] - (i-1>=0?prefs[i-1]:0);
            if(dectill[idx] == 0) continue;
            long long nidx = dectill[idx]+idx;
            if(nidx>=n) continue;
            curs += prefs[nidx] - prefs[idx];
            if(inctill[nidx] == 0) continue;
            idx = inctill[nidx]+nidx;


            long long exsum1 = prefs[idx] - prefs[nidx];
            long long exsum2 = prefs[nidx+1] - prefs[nidx];
            curs += max(exsum1, exsum2);
            ans = max(ans, curs);
        }

        return ans;
    }
};