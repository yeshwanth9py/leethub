// Last updated: 6/11/2026, 11:13:02 AM
class Solution {
public:
    long long getsum(long long n){
        return (1LL*n*(n+1))/2;
    }
    
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        vector<int> ans;
        if(getsum(n)<abs(target)) return {};
        if(getsum(n)%2 != abs(target)%2) return {};
        
        for(long long i=n; i>=1; i--){
            long long ntar = target+i;
            if(getsum(i-1)>=abs(ntar) && getsum(i-1)%2 == abs(target+i)%2){
                ans.push_back(-i);
                target = ntar;
            }else{
                ans.push_back(i);
                target = target-i;
            }
        }

        sort(ans.begin(), ans.end());
        
        return ans;
    }
};


