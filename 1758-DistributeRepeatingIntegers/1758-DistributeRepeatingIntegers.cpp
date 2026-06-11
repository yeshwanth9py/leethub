// Last updated: 6/11/2026, 11:26:39 AM
class Solution {
    int m, FULL;
    vector<int> sizes;
    vector<int> quantity;
    vector<int> subsetSum;
    // memo[b][mask] = -1 (unknown), 0 (false), 1 (true)
    vector<unordered_map<int,char>> memo;

    bool dfs(int b, int mask) {
        if (mask == FULL) 
            return true;                     // all requests done
        if (b == (int)sizes.size()) 
            return false;                    // no buckets left

        auto &mp = memo[b];
        if (mp.count(mask)) 
            return mp[mask];                // return cached result

        int cap = sizes[b];
        int rem = FULL ^ mask;               // bits not yet covered

        // Try every non-empty submask of rem
        // Start at rem, then iterate down: 
        for (int sub = rem; sub; sub = (sub - 1) & rem) {
            // If this bucket can cover 'sub'
            if (subsetSum[sub] <= cap) {
                // assign 'sub' here and recurse
                if (dfs(b + 1, mask | sub)) {
                    return mp[mask] = 1;
                }
            }
        }

        // Also, choose *not* to use this bucket at all
        if (dfs(b + 1, mask)) {
            return mp[mask] = 1;
        }

        return mp[mask] = 0;
    }

public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity_) {
        quantity = quantity_;
        m = quantity.size();
        FULL = (1 << m) - 1;

        // 1) Build bucket capacities
        unordered_map<int,int> freq;
        for (int x : nums) freq[x]++;
        for (auto &p : freq) 
            sizes.push_back(p.second);

        // 2) Precompute subset sums
        int ALL = FULL + 1;
        subsetSum.assign(ALL, 0);
        for (int mask = 1; mask <= FULL; ++mask) {
            // __builtin_ctz(mask) gives the index of the
            // least-significant 1-bit in mask.
            // E.g. mask=0b1011000 → returns 3 (zero-based).
            int bit = __builtin_ctz(mask);
            subsetSum[mask] = subsetSum[mask ^ (1 << bit)]
                             + quantity[bit];
        }

        // 3) Prepare memo table
        memo.resize(sizes.size());

        // 4) Start recursion from bucket 0, no requests done
        return dfs(0, 0);
    }
};
