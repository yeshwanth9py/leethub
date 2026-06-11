// Last updated: 6/11/2026, 11:14:15 AM
class Solution {
public:
    long long maxProfit(vector<int>& pri, vector<int>& str, int k) {
        long long n = pri.size();
        vector<long long> pre(n, 0);
        vector<long long> prepri(n, 0);

        for(long long i=0; i<n; i++){
            pre[i] = str[i]*pri[i];
            pre[i] = ((i-1>=0)?pre[i-1]:0) + pre[i];

            prepri[i] = pri[i];
            if(i){
                prepri[i] += prepri[i-1];
            }
        }

        long long tot = pre[n-1];
        long long ans = tot;
        for(long long i=0; i<n; i++){
            long long s = i;
            long long l = s+k-1;
            if(l>=n) continue;
            long long cur = tot - (pre[l]-(s-1>=0?pre[s-1]:0));
            long long mid = prepri[l] - ((l-(k/2)>=0)?prepri[l-(k/2)]:0);
            // cout<<i<<" "<<cur<<" "<<mid<<endl;
            cur += mid;
            ans = max(ans, cur);
        }

        return ans;


    }
};