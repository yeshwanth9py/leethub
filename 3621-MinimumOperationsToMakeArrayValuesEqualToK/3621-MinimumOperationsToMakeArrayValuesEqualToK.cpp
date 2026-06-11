// Last updated: 6/11/2026, 11:17:26 AM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int minel = *min_element(nums.begin(), nums.end());
        if(k>minel) return -1;
        unordered_map<int, int> ump;
        int n = nums.size();
        for(int i=0; i<n; i++){
            ump[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for(auto el: ump){
            pq.push({el.first, el.second});
        }
        int op = 0;
        while(pq.size()>1){
            auto tel = pq.top();
            pq.pop();
            auto ntel = pq.top();
            pq.pop();
            pq.push({ntel.first, ntel.second+tel.second});
            op++;
        }
        if(pq.top().first == k){
            return op;
        }else if(pq.top().first>k){
            return op+1;
        }else{
            return -1;
        }
        


    }
};