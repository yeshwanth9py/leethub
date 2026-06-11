// Last updated: 6/11/2026, 11:10:23 AM
struct Binl{
    int dp[100100][21];
    int n;
    Binl(vector<int> &nums){
        n = nums.size();
        for(int i=0; i<n; i++){
            dp[i][0] = nums[i];
        }
        for(int j=1; j<21; j++){
            for(int i=0; i<n; i++){
                dp[i][j] = dp[i][j-1];
                if(i+(1LL<<(j-1))<n){
                    dp[i][j] |= dp[i+(1LL<<(j-1))][j-1];
                }
            }
        }
    }

    int query(int l, int r){
        int dif = r-l+1;
        dif = log2(dif);
        int ans = (dp[l][dif] | dp[r-(1LL<<dif)+1][dif]);
        // int cur = l;
        // for(int i=20; i>=0; i--){
        //     if(dif&(1LL<<i)){
        //         ans |= dp[cur][i];
        //         cur = cur+(1LL<<i);
        //     }
        // }
        return ans;
    }
};


class Solution {
public:
    long long countGoodSubarrays(vector<int>& nums) {
        unordered_map<int, int> ump;
        int n = nums.size();
        vector<int> prevs(n, -1);
        for(int i=0; i<n; i++){
            if(ump.find(nums[i]) != ump.end()){
                prevs[i] = ump[nums[i]];
            }
            ump[nums[i]] = i;
        }

        Binl sg(nums);

        long long tot = 0;
        for(int i=0; i<n; i++){
            int jl=i;
            int lo = 0;
            int hi = i;
            int ans = i;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(sg.query(mid, jl) == nums[i]){
                    ans = mid;
                    hi = mid-1;
                }else{
                    lo = mid+1;
                }
            }
            jl = ans;
            
            lo = i;
            hi = n-1;
            int jr = i;
            ans = i;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(sg.query(i, mid) == nums[i]){
                    ans = mid;
                    lo = mid+1;
                }else{
                    hi = mid-1;
                }
            }

            jr = ans;

            if(prevs[i] != -1 && prevs[i]>=jl){
                jl = prevs[i]+1;
            }

            tot += (i-jl+1)*(jr-i+1);
        }

        return tot;
        
    }
};