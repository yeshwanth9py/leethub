// Last updated: 6/11/2026, 11:27:09 AM
class Solution {
public:
    bool check(int mid, vector<int>& arr, int k){
        cout<<"mid"<<mid<<" ";
        int temp1 = (upper_bound(arr.begin(), arr.end(), mid)-arr.begin());
        return mid-temp1>=k;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int low = 1;
        int high = arr[arr.size()-1]+k;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(check(mid, arr, k)){
                ans = mid;
                high = mid-1;
            } else{
                low = mid+1;
            }
        }

        return ans;
    }
};