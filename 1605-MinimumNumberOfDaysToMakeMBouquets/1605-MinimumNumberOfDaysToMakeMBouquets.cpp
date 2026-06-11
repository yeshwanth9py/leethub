// Last updated: 6/11/2026, 11:27:24 AM
class Solution {
public:
    bool checker(int md, vector<int> &arr, int k, int m){
        int n = arr.size();
        int i=0;
        int j=-1;
        int cnt = 0;
        while(i<n){
            while(j+1<n && arr[j+1]<=md && j-i+1<k){
                j++;
            }
            if(j-i+1==k){
                cnt++;
            }
            if(i>j){
                i++;
                j=i-1;
            }else{
                i=j+1;
            }
        }

        return cnt>=m;
    }

    int minDays(vector<int>& arr, int m, int k) {
        int lo = 0;
        int hi = *max_element(arr.begin(), arr.end());
        int ans = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(checker(mid, arr, k, m)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;

    }
};