// Last updated: 6/11/2026, 11:21:04 AM
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long,long long> ump;
        unordered_map<long long,long long> cnt;

        unordered_map<long long,long long> prev;
        unordered_map<long long,long long> pcnt;

        long long n = nums.size();
        vector<long long> arr(n, 0);

        for(long long i=0; i<n; i++){
            cnt[nums[i]]++;
            ump[nums[i]] += i;
        }

        for(long long i=0; i<n; i++){
            long long el = nums[i];
            ump[el] -= i;
            cnt[el]--;
            long long ps = prev[el];
            long long c = pcnt[el];

            long long cur = c*i - ps;

            long long ns = ump[el];
            long long cs = cnt[el];
            cur += ns - i*cs;
            arr[i] = max(0LL, cur);

            prev[el] += i;
            pcnt[el] += 1;
        }

        return arr;
    }
};