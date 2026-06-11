// Last updated: 6/11/2026, 11:17:12 AM
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> magic(n, 0);
        for(int i=0; i<queries.size(); i++){
            if(queries[i][0]>queries[i][1]){
                swap(queries[i][0], queries[i][1]);
            }
            magic[queries[i][0]]++;
            if(queries[i][1]+1<n){
                magic[queries[i][1]+1]--;
            }
        }
        int psum = 0;
        for(int i=0; i<n; i++){
            psum += magic[i];
            if(psum<nums[i]) return 0;
        }

        return 1;
    }

};