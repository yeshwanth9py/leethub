// Last updated: 6/11/2026, 11:27:34 AM
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        long long n = s.size();
        if(n<k) return 0;
        unordered_map<long long, long long> ump;
        long long myn = 0;
        for(long long i=0; i<k; i++){
            myn = myn*2 + ((s[i] == '1')?1:0);
        }
        ump[myn]++;
        long long i=0;
        myn -= ((1LL<<(k-1))*(s[i] == '1'));
        long long j = k-1;
        j++;
        i++;
        while(j<n){
            myn = myn*2 + (s[j] == '1');
            ump[myn]++;
            myn -= ((1LL<<(k-1))*(s[i] == '1'));
            i++;
            j++;
        }

        if(ump.size() >= (1LL<<k)){
            return 1;
        }
        return 0;
    }
};