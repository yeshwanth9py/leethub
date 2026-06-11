// Last updated: 6/11/2026, 11:14:12 AM
class Solution {
public:
    vector<pair<int, int>> arr;
    vector<int> wall;
    int n;
    int dp[101100][2];
    int rec(int ind, int prev, int pp){  //0 left , 1 right
        if(ind == n) return 0;
        if(dp[ind][prev] != -1) return dp[ind][prev];
        int ri = 0;
        auto it = lower_bound(wall.begin(), wall.end(), arr[ind].first);
        if(it != wall.end()){
            int idx = it-wall.begin();
            if(wall[idx]-arr[ind].first <= arr[ind].second && (ind+1==arr.size() || (ind+1<arr.size() && arr[ind+1].first>wall[idx]))){
                int lo = idx;
                int hi = wall.size()-1;

                int ans = lo;
                while(lo<=hi){
                    int mid = (lo+hi)/2;
                    if(wall[mid]-arr[ind].first<=arr[ind].second && (ind+1==arr.size() || (ind+1<arr.size() && arr[ind+1].first>wall[mid]))){
                        ans = mid;
                        lo = mid+1;
                    }else{
                        hi = mid-1;
                    }
                }
                ri = ans-idx+1 + rec(ind+1, 1, ans);
            }
        }

        int li = 0;
        it = upper_bound(wall.begin(), wall.end(), arr[ind].first);
        if(it != wall.begin()){
            it--;
            int idx = it-wall.begin();

            if(arr[ind].first-wall[idx]<=arr[ind].second && (ind-1<0 || (ind-1>=0 && arr[ind-1].first<wall[idx])) ){
                int lo = 0;
                int hi = idx;
                int ans = hi;
                while(lo<=hi){
                    int mid = (lo+hi)/2;
                    if(arr[ind].first-wall[mid]<=arr[ind].second && (ind-1<0 || (ind-1>=0 && arr[ind-1].first<wall[mid])) ){
                        ans = mid;
                        hi = mid-1;
                    }else{
                        lo = mid+1;
                    }
                }
                ans = max(pp+1, ans);
                if(ans<=idx) li = idx-ans+1 + rec(ind+1, 0, -1);
            }
        }
        if(li == 0 && ri == 0){
            return dp[ind][prev] = rec(ind+1, 0, -1);
        }

        return dp[ind][prev] = max(li, ri);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        n = robots.size();
        arr.resize(n);
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            arr[i] = {robots[i], distance[i]};
        }
        sort(arr.begin(), arr.end());

        wall = walls;
        sort(wall.begin(), wall.end());

        return rec(0, 0, -1);

    }
};