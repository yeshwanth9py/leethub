// Last updated: 6/11/2026, 11:26:24 AM
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        pq.push({nums[0], 0});
        for(int i=1; i<nums.size(); i++){
            // auto p = pq.top();
            // pq.pop();
            while(i - pq.top().second > k){
                pq.pop();
            }

            if(i - pq.top().second <= k){
                pq.push({nums[i]+pq.top().first, i});
            }

        }

        while(pq.top().second!=nums.size()-1){
            pq.pop();
        }
        return pq.top().first;
    }
};