// Last updated: 6/11/2026, 11:11:12 AM
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        if(k == 0) return nums;
        vector<int> kelem;
        int n = nums.size();
        vector<int> mark(n, 0);
        for(int i=0; i<n; i++){
            if(nums[i]>=0){
                kelem.push_back(nums[i]);
                mark[i] = 1;
            }else{
                continue;
            }
        }

        int m = kelem.size();
        if(m == 0){
            return nums;
        }
        k = k%m;
        int j = k;
        // cout<<j<<" ";
        
        for(int i=0; i<n; i++){
            if(mark[i] == 1){
                // cout<<allnon[j]<<" ";
                nums[i] = kelem[j];
                j++;
                j = j%m;
            }
        }

        return nums;
    }
};