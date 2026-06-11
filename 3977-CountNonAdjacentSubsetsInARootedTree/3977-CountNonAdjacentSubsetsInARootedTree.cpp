// Last updated: 6/11/2026, 11:14:17 AM
class Solution {
public:
    vector<vector<int>> dp1;
    vector<vector<int>> dp0;
    int n;
    int k;
    vector<vector<int>> adjl;
    vector<int> arr;
    const int mod = 1e9+7;

    void rec(int node){
        int v = arr[node]%k;

        dp1[node][v] = 1;
        dp0[node][0] = 1;

        for(int nei: adjl[node]){
            rec(nei);
            vector<int> newdp1(k, 0);
            vector<int> newdp0(k, 0);

            for(int i=k-1; i>=0; i--){
                for(int j=k-1; j>=0; j--){
                    newdp1[(i+j)%k] += (1LL*dp1[node][i]*dp0[nei][j])%mod;
                    newdp1[(i+j)%k] = (newdp1[(i+j)%k]%mod + mod)%mod;
                    newdp0[(i+j)%k] += ((1LL*dp0[node][i]*dp1[nei][j])%mod + (1LL*dp0[node][i]*dp0[nei][j])%mod)%mod; 
                    newdp0[(i+j)%k] = newdp0[(i+j)%k]%mod;
                }
            }

            for(int i=0; i<k; i++){
                dp1[node][i] = newdp1[i];
                dp0[node][i] = newdp0[i];
            }
        }
    }

    int countValidSubsets(vector<int>& parent, vector<int>& nums, int k) {
        n = parent.size();
        adjl.resize(n, vector<int>());

        arr = nums;
        this->k = k;
        for(int i=1; i<n; i++){
            int pp = parent[i];
            adjl[pp].push_back(i);
        }
        dp1.resize(n, vector<int>(k, 0));
        dp0.resize(n, vector<int>(k, 0));

        rec(0);

        return ((dp1[0][0] + dp0[0][0])%mod -1 + mod)%mod;

    }
};