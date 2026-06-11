// Last updated: 6/11/2026, 11:33:41 AM
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for(int el: nums){
            ump[el]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto el: ump){
            pq.push({el.second, el.first});
        }

        vector<int> ans;
        
        while(!pq.empty() && k>0){
            auto tel = pq.top(); pq.pop();
            ans.push_back(tel.second);
            k--;
        }

        return ans;
    }
};