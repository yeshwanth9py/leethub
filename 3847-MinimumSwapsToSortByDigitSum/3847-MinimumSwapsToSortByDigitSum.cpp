// Last updated: 6/11/2026, 11:15:13 AM
class Solution {
public:
    int dsum(int num){
        int ts = 0;
        while(num){
            ts += num%10;
            num /= 10;
        }
        return ts;
    }
    int minSwaps(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> ump;
        for(int i=0; i<nums.size(); i++){
            int ds = dsum(nums[i]);
            // cout<<ds<<" ";
            ump[nums[i]] = i;
            pq.push({ds, nums[i]});
        }
        
        // cout<<endl;

        int msw = 0;
        for(int i=0; i<nums.size(); i++){
            auto tel = pq.top(); pq.pop();
            // cout<<tel.second<<","<<ump[tel.second]<<"  ";
            if(tel.second == nums[i]){
                continue;
            }else{
                msw++;
                ump[nums[i]] = ump[tel.second];
                swap(nums[i], nums[ump[tel.second]]);
            }
        }

        return msw;
    }
    
};