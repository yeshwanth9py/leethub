// Last updated: 6/11/2026, 11:17:50 AM
using ll = long long;
class Solution {
public:
    int n;
    int k;
    unordered_set<string> pre;
    ll dp[11];
    ll fact(int a){
        if(a == 0) return 1;
        if(dp[a]!=-1) return dp[a];
        return dp[a] = a*fact(a-1);
    }

    ll rec(int ind, string nums){
        if(ind > (n-1)/2){
            ll numb = stoll(nums);
            if(numb%k != 0){
                return 0;
            }
            sort(nums.begin(), nums.end());
            if(pre.count(nums)>0){
                return 0;
            }
            unordered_map<int, int> ump;
            for(int i=0; i<n; i++){
                ump[nums[i]-'0']++;
            }
            int valid = fact(n);
            for(auto el: ump){
                if(el.second>1){
                    valid = valid/fact(el.second);
                }
            }
            int invalid = 0;
            if(ump[0]>=1){
                invalid = fact(n-1);
                ump[0]--;
                for(auto el: ump){
                    if(el.second>1){
                        invalid = invalid/fact(el.second);
                    }
                }
            }
            pre.insert(nums);
            return valid-invalid;
        }

        int st = 0;
        if(ind == 0){
            st = 1;
        }
        int ways = 0;
        for(int i=st; i<=9; i++){
            nums[ind] = i+'0';
            nums[n-ind-1] = i+'0';
            // cout<<nums<<" ";
            ways += rec(ind+1, nums);
        }
        return ways;
    }

    long long countGoodIntegers(int n, int k) {
        this->n = n;
        this->k = k;
        memset(dp, -1, sizeof(dp));
        string nums = "";
        for(int i=0; i<n; i++){
            nums += "0";
        }
        return rec(0, nums);
    }
};