// Last updated: 6/11/2026, 11:13:36 AM
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long lastel = nums2.back();
        long long mind = 1e18;
        // long long cur = 1e9;
    
        for(long long i=0; i<nums1.size(); i++){
            if(nums1[i]<=lastel && lastel<=nums2[i]){
                mind = 0;
            }
            if(nums2[i]<=lastel && lastel<=nums1[i]){
                mind = 0;
            }
            
            if(abs(nums1[i]-lastel)<mind){
                mind = abs(nums1[i]-lastel);
            }
            
            if(abs(nums2[i]-lastel)<mind){
                mind = abs(nums2[i]-lastel);
            }
        }
        
        // cout<<cur<<" ";
        
        long long ans = 0;
        for(long long i=0; i<nums1.size(); i++){
            // cout<<abs(nums1[i]-nums2[i])<<" ";
            ans += abs(nums1[i]-nums2[i]);
        }

        // cout<<mind+1<<" ";
        ans += mind+1;

        return ans;
        
    }
};