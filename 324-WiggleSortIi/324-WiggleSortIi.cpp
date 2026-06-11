// Last updated: 6/11/2026, 11:33:48 AM
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int range = *max_element(nums.begin(), nums.end());
        vector<int> freq(range+1, 0);
        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        //cumulative frequency
        for(int i=1; i<=range; i++){
            freq[i] = freq[i-1]+freq[i];
        }

        vector<int> sortarr(n, 0);

        for(int i=n-1; i>=0; i--){
            int cnt = freq[nums[i]];
            sortarr[cnt-1] = nums[i];
            freq[nums[i]]--;
        }

        int high = sortarr.size()-1;
        int low = (sortarr.size()-1)/2;

        vector<int> nnums(nums.size(), 0);
        for(int i=0; i<sortarr.size(); i++){
            if(i%2==0){
                nnums[i] = sortarr[low];
                low--;
            }else{
                nnums[i] = sortarr[high];
                high--;
            }
        }

        nums = nnums;
    }
};