// Last updated: 6/11/2026, 11:29:08 AM
class Solution {
public:
    int n;
    int solve(string &s, char ch){
        vector<int> prev(n, 0);
        vector<int> next(n, 0);

        vector<int> prevex(n, 0);
        vector<int> nextex(n, 0);

        int sum = 0;
        int ex = 0;
        for(int i=0; i<n; i++){
            if(s[i] == ch){
                sum++;
                ex = 1;
            }else {
                sum = 0;
            }
            prev[i] = sum;
            prevex[i] = ex;
        }

        sum = 0;
        ex = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == ch){
                sum++;
                ex = 1;
            }else{
                sum = 0;
            }
            next[i] = sum;
            nextex[i] = ex;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] != ch){
                int pr = i-1;
                int cur = 0;
                if(i-1>=0){
                    cur += prev[i-1];
                    pr = pr-prev[i-1];
                }
                int nn = i+1;
                if(i+1<n){
                    cur += next[i+1];
                    nn = nn+next[i+1];
                }
                int tot = 0;
                if(pr>=0){
                    tot += prevex[pr];
                }
                if(nn<n){
                    tot +=nextex[nn];
                }
                // cout<<i<<" "<<pr<<" "<<nn<<" "<<tot<<" "<<cur<<endl;
                if(tot>0){
                    ans = max(ans, 1+cur);
                }else{
                    ans = max(ans, cur);
                }
            }else{
                ans = max(ans, prev[i]);
            }
        }

        return ans;
    }

    int maxRepOpt1(string text) {
        int ans = 0;
        n = text.size();
        for(char ch='a'; ch<='z'; ch++){
            ans = max(ans, solve(text, ch));
        }
        return ans;
    }
};