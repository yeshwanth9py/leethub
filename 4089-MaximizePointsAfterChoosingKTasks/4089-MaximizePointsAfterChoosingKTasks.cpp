// Last updated: 6/11/2026, 11:12:51 AM
class Solution {
public:
    long long maxPoints(vector<int>& arr1, vector<int>& arr2, int k) {
        vector<pair<long long, long long>> sums;
        long long n = arr1.size();
        for(long long i=0; i<n; i++){
            sums.push_back({arr1[i]-arr2[i], i});
        }

        sort(sums.begin(), sums.end());

        long long i=n-1;
        long long taken = 0;
        long long sym =0;
        long long j = 0;
        while(taken<n){
            if(taken<k || sums[i].first>=0){
                long long cind = sums[i].second;
                sym += arr1[cind];
                taken++;
                i--;
            }else{
                long long cind = sums[j].second;
                sym += arr2[cind];
                j++;
                taken++;
            }
        }
        
        return sym;
        
    }
};