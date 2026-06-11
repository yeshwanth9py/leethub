// Last updated: 6/11/2026, 11:15:16 AM
class Solution {
public:
    vector<vector<long long>> adjl;
    vector<long long> dep;
    const long long mod = 1e9+7;
    long long fact[100101];
    // long long invfact[100101];
    
    long long binpow(long long x, long long n){
        if(n == 0) return 1;
        if(n == 1) return x;
        long long ans = binpow(x, n/2);
        ans = ((ans * ans)%mod + mod)%mod;
        if(n&1){
            ans = ((ans*x)%mod + mod)%mod;
        }
        return ans;
    }

    void pre(){
        fact[0] = fact[1] = 1;
        for(long long j=2; j<100101; j++){
            fact[j] = ((fact[j-1]*j)%mod + mod)%mod;
        }
        // cout<<invfact[1]<<"\n";
    }

    void dfs(long long node, long long pp, long long dd){
        dep[node] = dd;
        for(long long nei: adjl[node]){
            if(nei != pp){
                dfs(nei, node, dd+1);
            }
        }
    }

    long long ncr(long long n, long long r){
        if(r == 0) return 1;
        long long num = fact[n];
        long long den = ((fact[n-r]*fact[r])%mod + mod)%mod;
        num = ((num*binpow(den, mod-2))%mod + mod)%mod;
        return num;
    }

    long long assignEdgeWeights(vector<vector<int>>& edg) {
        long long n = edg.size()+1;
        pre();

        adjl.resize(n, vector<long long>());
        dep.resize(n, 0);

        for(long long i=0; i<n-1; i++){
            long long u = edg[i][0];
            long long v = edg[i][1];
            u--;
            v--;
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }

        dfs(0, -1, 0);

        long long mx = 0;
        for(long long i=0; i<n; i++){
            if(dep[i]>dep[mx]){
                mx = i;
            }
        }

        long long maxdep = dep[mx];

        // cout<<maxdep<<" ";

        long long ans = 0;
        if(maxdep%2 == 1){
            for(long long j=0; j<maxdep; j=j+2){
                ans += ncr(maxdep, j);
                ans = (ans%mod + mod)%mod;
            }
            return ans;
        }else{
            for(long long j=1; j<=maxdep; j=j+2){
                ans += ncr(maxdep, j);
                ans = (ans%mod + mod)%mod;
            }
            return ans;
        }
    }
};