// Last updated: 6/11/2026, 11:33:38 AM
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        vector<int> ans;
        for(auto el: s2){
            if(s1.count(el)>0){
                ans.push_back(el);
            }
        }
        return ans;
    }
};