// Last updated: 6/11/2026, 11:25:07 AM
class Solution {
public:
    static constexpr int MOD = 1'000'000'007;
    int colorTheGrid(int m, int n) {
        // 1) Generate valid column-masks (no two same vertically)
        vector<int> valid;
        int total = pow(3, m);
        for (int mask = 0; mask < total; ++mask) {
            bool ok = true;
            int x = mask, last = x % 3;  // bottom cell
            x /= 3;
            for (int i = 1; i < m; ++i) {
                if ((x % 3) == last) { ok = false; break; }
                last = x % 3;
                x /= 3;
            }
            if (ok) valid.push_back(mask);
        }

        // 2) Precompute compatibility between columns
        int V = valid.size();
        vector<vector<int>> compat(V);
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                bool ok = true;
                int a = valid[i], b = valid[j];
                for (int r = 0; r < m; ++r) {
                    if ((a % 3) == (b % 3)) {
                        ok = false;
                        break;
                    }
                    a /= 3;
                    b /= 3;
                }
                if (ok) compat[i].push_back(j);
            }
        }

        // 3) DP over n columns with rolling arrays
        vector<int> dp_prev(V, 1), dp_curr(V, 0);
        for (int col = 1; col < n; ++col) {
            fill(dp_curr.begin(), dp_curr.end(), 0);
            for (int i = 0; i < V; ++i) {
                for (int j : compat[i]) {
                    dp_curr[j] = (dp_curr[j] + dp_prev[i]) % MOD;
                }
            }
            dp_prev.swap(dp_curr);
        }

        // 4) Sum up ways for the last column
        long long ans = 0;
        for (int x : dp_prev) ans = (ans + x) % MOD;
        return int(ans);
    }
};
