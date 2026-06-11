// Last updated: 6/11/2026, 11:23:12 AM
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        vector<int> pos;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] == key){
                pos.push_back(i);
            }
        }

        for(int i=0; i<n; i++){
            // if(i-k>=0){
            auto it = lower_bound(pos.begin(), pos.end(), i-k);
            if(it!=pos.end() && abs(i-*it) <= k){
                cout<<key<<" "<<(*it)<<endl;
                ans.push_back(i);
                continue;
            }
            // }
            it = lower_bound(pos.begin(), pos.end(), i+k);

            if(it != pos.end() && abs(*it-i)<=k){
                // cout<<i<<endl;
                ans.push_back(i);
            }
        }

        return ans;





    }
};