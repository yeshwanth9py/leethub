// Last updated: 6/11/2026, 11:16:29 AM
class Solution {
public:
    int n;
    vector<vector<int>> arr;
    unordered_map<int, vector<int>> ump;
    int dp[1011][1501][2];
    vector<int> getpfacts(int el){
        vector<int> temp;
        for(int i=2; i*i<=el; i++){
            if(el%i == 0){
                temp.push_back(i);
                while(el%i == 0){
                    el = el/i;
                }
            }
        }
        
        if(el>1){
            temp.push_back(el);
        }
        
        return temp;
    }
    
    int rec(int ind, int rem, int buy){
        if(rem<0) return 0;
        if(ind>=n) return 0;

        if(dp[ind][rem][buy] != -1) return dp[ind][rem][buy];
        //buy
        int ans = rec(ind+1, rem, 0);
        
        if(arr[ind][1]<=rem){
            int cur = 1 + rec(ind, rem-arr[ind][1], 1);
            if(buy == 0){
                vector<int> &temp = ump[arr[ind][0]];
                int ex = temp.size();
                cur += ex;
            }
            ans = max(ans, cur);
        }

        return dp[ind][rem][buy] = ans;
    }
    
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        sort(items.begin(), items.end(), [&](vector<int> &a, vector<int> &b){
            return a[1]<b[1];
        });
        arr = items;
        n = arr.size();
        memset(dp, -1, sizeof(dp));
        ump.clear();
        for(int i=0; i<n; i++){
            int el = items[i][0];
            if(ump.find(el) != ump.end()) continue;
            for(int j=0; j<n; j++){
                if(j == i) continue;
                int fel = items[j][0];
                if(fel%el == 0){
                    ump[el].push_back(j);
                }
            }
        }
        
        
        return rec(0, budget, 0);
    }
};