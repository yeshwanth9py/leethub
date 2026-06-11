// Last updated: 6/11/2026, 11:28:26 AM
class Solution {
public:
    bool check(int mid, vector<int>& nums, int threshold){
        long long anss = 0;
        cout<<"mid"<<mid<<endl;
        for(int i=0; i<nums.size(); i++){
            anss+=ceil(nums[i]/(1.0*mid));
            // cout<<ceil(nums[i]/(1.0*mid))<<" ";
        }
        // cout<<endl;
        return anss<=threshold;
    }

    long long smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(mid, nums, threshold)){
                ans = mid;
                high = mid-1;
            } else{
                low = mid+1;;
            }
        }

        return ans;




    }
};