// Last updated: 6/11/2026, 11:26:36 AM
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int ts = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<int> ans(n, 0);

        vector<pair<int, int>> vec;

        int ps = 0;
        for(int i=0; i<n; i++){
            vec.push_back({nums[i], i});
        }
        sort(vec.begin(), vec.end());

        for(int i=0; i<n; i++){
            int el = vec[i].first;
            int ind = vec[i].second;

            ts -= el;

            int cur = (el*i - ps);
            cur += ts - el*(n-i-1);

            ps += el;

            ans[ind] = cur;
        }

        return ans;
    }
};