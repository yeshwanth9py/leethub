// Last updated: 6/11/2026, 11:10:49 AM
class Solution {
public:
    vector<long long> pref;
    long long n;
    long long ec;
    long long fc;
    string s;
    map<pair<long long, long long>, long long> mp;
    long long getcost(long long l, long long x){
        if(x == 0) return fc;
        return l*x*ec;
    }

    long long rec(long long l, long long r){
        if(l == r){
            return getcost(1, s[l]=='1');
        }
        if(mp.find({l, r}) != mp.end()) return mp[{l, r}];
        long long len = r-l+1;
        long long c1 = getcost(len, pref[r]-(l-1>=0?pref[l-1]:0));
        if((len%2) == 0){
            c1 = min(c1, rec(l, l+(len/2)-1)+rec(l+(len/2), r));
        }
        return mp[{l, r}] = c1;
    }
    
    long long minCost(string s, long long encCost, long long flatCost) {
        n = s.size();
        this->s = s;
        pref.resize(n, 0);
        ec = encCost;
        fc = flatCost;
        mp.clear();
        for(long long i=0; i<n; i++){
            pref[i] = (i-1>=0?pref[i-1]:0);
            if(s[i] == '1'){
                pref[i] += 1;
            }
        }


        return rec(0, n-1);

        
    }
};