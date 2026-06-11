// Last updated: 6/11/2026, 11:11:38 AM
class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> store;
        for(int el: nums){
            int numbr = 0;
            int len = log2(el)+1;
            int j = len-1;
            for(int i=0; i<len; i++){
                if((el&(1LL<<i)) != 0){
                    numbr += (1LL<<j);
                }
                j--;
            }
            // cout<<el<<" "<<numbr<<endl;
            store.push_back({numbr, el});
        }

        sort(store.begin(), store.end());

        vector<int> other;
        for(auto el: store){
            other.push_back(el.second);
        }
        
        return other;
    }
};