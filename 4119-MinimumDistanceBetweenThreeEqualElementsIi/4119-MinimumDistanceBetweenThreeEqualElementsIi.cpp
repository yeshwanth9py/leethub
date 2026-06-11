// Last updated: 6/11/2026, 11:12:28 AM
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> ump1;

        int n = nums.size();
        
        for(int i=0; i<n; i++){
            ump1[nums[i]].push_back(i);
        }

        int mind = 2e9;
        for(int i=1; i<n-1; i++){
            auto it = lower_bound(ump1[nums[i]].begin(), ump1[nums[i]].end(), i);
            if((it==ump1[nums[i]].begin()) || (it == ump1[nums[i]].end())) continue;
            auto pit = it-1;
            auto fit = it+1;
            if((fit == ump1[nums[i]].end())) continue;
            
            int pind = *(pit);
            int nind = *(fit);
            
            mind = min(mind, 2*(nind-pind));
        }
        if(mind>=1e8) return -1;
        return mind;
    }
};