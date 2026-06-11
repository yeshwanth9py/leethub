// Last updated: 6/11/2026, 11:28:43 AM
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_set<int> un;
        for(int i=0; i<nums.size(); i++){
            un.insert(nums[i]);
        }

        vector<int> nnums;
        while(!un.empty()){
            nnums.push_back(*un.begin());
            un.erase(un.begin());
        }
        
        int n = nnums.size();

        unordered_map<int, int> ans2;
        int cnt = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int prod = nums[i]*nums[j];
                 ans2[prod]++;
            }
        }
        int ans = 0;
        for(auto el: ans2){
            if(el.second>=2){
                int cn = el.second;
                cout<<el.first<<" "<<el.second<<endl;
                cout<<(cn*(cn-1)*4)<<endl;
                ans += (cn*(cn-1)*4);
            }
        }
        return ans;
    }
};