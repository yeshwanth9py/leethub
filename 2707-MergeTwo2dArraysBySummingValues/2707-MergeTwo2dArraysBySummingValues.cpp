// Last updated: 6/11/2026, 11:21:12 AM
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> ump;
        for(int i=0; i<nums1.size(); i++){
            ump[nums1[i][0]]+=nums1[i][1];
        }
        for(int i=0; i<nums2.size(); i++){
            ump[nums2[i][0]]+=nums2[i][1];
        }

        vector<vector<int>> ans;
        for(auto el: ump){
            ans.push_back({el.first, el.second});
        }
        return ans;


    }
};