// Last updated: 6/11/2026, 11:27:27 AM
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int j = -1;
        int n = nums.size();
        bool f = 0;
        int rs = 0;
        int maxs = 0;
        while(i<n){
            while(j+1<n && (nums[j+1] == 1 || (f == 0))){
                j++;
                if(nums[j] == 0){
                    f = 1;
                }else{
                    rs+=1;
                }
                cout<<rs<<" ";
            }
            if(j-i+1>=0){
                maxs = max(maxs, rs-(!f));
            }
            if(j<i){
                i++;
                j = i-1;
            }else{
                if(nums[i] == 0){
                    f = 0;
                }else{
                    rs-=1;
                }
                i++;
            }
        }

        return maxs;
    }
};