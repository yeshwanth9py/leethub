// Last updated: 6/11/2026, 11:19:17 AM
class Solution {
public:
    int n;
    string s;
    int k;
    map<tuple<int, long long, bool>, int> mp; 
    int rec(int ind, int mask, int canchange){
        if(ind >= n){
            if(mask) return 1;
            return 0;
        }
        if(mp[{ind, mask, canchange}] != 0){
            return mp[{ind, mask, canchange}];
        }

        int ans = 0;

        int ch = s[ind]-'a';
        int nmask = (mask | (1LL<<ch));
        int dist = __builtin_popcount(nmask);

        if(dist>k){
            ans = max(ans, 1+rec(ind+1, (1LL<<ch), canchange));
        }else{
            ans = max(ans, rec(ind+1, nmask, canchange));
        }

        if(canchange){
            for(int i=0; i<26; i++){
                nmask = (mask | (1LL<<i));
                dist = __builtin_popcount(nmask);
                if(dist>k){
                    ans = max(ans, 1+rec(ind+1, (1LL<<i), false));
                }else{
                    ans = max(ans, rec(ind+1, nmask, false));
                }
            }
        }

        return mp[{ind, mask, canchange}] = ans;
    }


    int maxPartitionsAfterOperations(string ss, int kk) {
        s = ss;
        k = kk;
        n = s.size();
        return rec(0, 0, 1);

    }
};