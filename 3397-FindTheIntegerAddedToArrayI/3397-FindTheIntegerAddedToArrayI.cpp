// Last updated: 6/11/2026, 11:18:31 AM
class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int s1 = accumulate(nums1.begin(), nums1.end(), 0);
        int s2 = accumulate(nums2.begin(), nums2.end(), 0);
        int ct = 0;
        for(int i=0; i<nums1.size(); i++){
            if(nums1[i]>=0){
                ct++;
            }else{
                ct--;
            }
        }
        return (s2-s1)/ct;
    }
};