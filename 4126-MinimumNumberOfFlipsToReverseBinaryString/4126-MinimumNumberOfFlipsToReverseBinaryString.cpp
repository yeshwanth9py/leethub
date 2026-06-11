// Last updated: 6/11/2026, 11:12:20 AM
class Solution {
public:
    int minimumFlips(int n) {
        int ans = 0;
        int l = log2(n);
        for(int i=l; i>=0; i--){
            int op = l-i;
            if((n&(1LL<<i))!=0 && (n&(1LL<<op))!=0) continue;
            if((n&(1LL<<i))==0 && (n&(1LL<<op))==0) continue;
            // cout<<i<<" "<<op<<endl;
            ans++;
        }

        return ans;

        
    }
};