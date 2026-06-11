// Last updated: 6/11/2026, 11:13:40 AM
class Solution {
public:
    long long n;
    long long dfs(long long nd, long long col, vector<long long> &vis, vector<vector<int>> &adjl){
        vis[nd] = col;
        for(long long nei: adjl[nd]){
            if(vis[nei] == 0){
                if(dfs(nei, ((col == 1)?2:1), vis, adjl) == 0) return 0;
            }else if(vis[nei] == col){
                return 0;
            }
        }

        return 1;
    }

    bool checkbipartite(vector<vector<int>> &adjl){
        vector<long long> vis(n, 0);
        for(long long i=0; i<n; i++){
            if(vis[i] == 0){
                if(dfs(i, 1, vis, adjl) == 0) return 0;
            }
        }
        return 1;
    }

    bool check(long long di, vector<vector<int>> &arr){
        vector<vector<int>> adjl(n, vector<int>());
        for(long long i=0; i<arr.size(); i++){
            for(long long j=i+1; j<n; j++){
                long long x2 = arr[j][0];
                long long y2 = arr[j][1];
                long long x1 = arr[i][0];
                long long y1 = arr[i][1];
                if(abs(x2-x1)+abs(y2-y1) < di){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }

        if(checkbipartite(adjl)){
            return 1;
        }

        return 0;
    }

    int maxPartitionFactor(vector<vector<int>>& arr) {
        if(arr.size() <= 2) return 0;
        long long lo = 0;
        n = arr.size();
        long long hi = 2e9;
        long long ans = -1;
        while(lo<=hi){
            long long mid = (lo+hi)/2;
            if(check(mid, arr)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        return ans;
    }
};