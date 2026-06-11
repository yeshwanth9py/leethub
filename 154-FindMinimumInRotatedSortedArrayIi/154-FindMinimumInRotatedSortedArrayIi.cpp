// Last updated: 6/11/2026, 11:35:31 AM
class Solution {
public:
    int ans;
    int l;
    int h;
    vector<int> arr;
    void find(int lo, int hi){
        if(lo>hi) return;
        
        int mid = (lo+hi)/2;
        if(arr[mid]>arr[l]){
            ans = min(ans, arr[l]);
            find(mid+1, hi);
            return;
        }else if(arr[mid]<arr[l]){
            ans = min(ans, arr[mid]);
            find(lo, mid-1);
            return;
        }else{
            if(arr[mid]>arr[h]){
                ans = min(ans, arr[h]);
                find(mid+1, hi);
                return;
            }else{
                ans = min(ans, arr[mid]);
                find(mid+1, hi);
                find(lo, mid-1);
            }
        }
    }
    int findMin(vector<int>& arr) {
        this->arr = arr;
        int n = arr.size();
        if(n<=3){
            int minel = arr[0];
            for(int i=1; i<n; i++) minel= min(minel, arr[i]);
            return minel;
        }
         
        if(arr[n-1]>arr[0]) return arr[0];

        ans = 1e9;

        l = 0;
        h = n-1;
        
        find(0, n-1);
        

        return ans;
    }
};