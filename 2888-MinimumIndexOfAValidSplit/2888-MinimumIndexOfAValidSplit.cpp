// Last updated: 6/11/2026, 11:20:39 AM
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int el = nums[0];
        int cnt = 0;
        for(int e: nums){
            if(e == el){
                cnt++;
            }else{
                cnt--;
                if(cnt <= 0){
                    el = e;
                    cnt = 1;
                }
            }
            // cout<<el<<" "<<cnt<<endl;
        }

        cout<<el<<endl;
        cnt = 0;
        for(int e: nums){
            if(e == el){
                cnt++;
            }
        }
        if(cnt<(nums.size())/2){
            return -1;
        }

        int mtn = 0;
        // int etn = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == el){
                mtn++;
            }

            if(mtn>(i+1)/2 && (cnt-mtn)>(n-i-1)/2){
                return i;
            }
        }
        return -1;
        




    }
};