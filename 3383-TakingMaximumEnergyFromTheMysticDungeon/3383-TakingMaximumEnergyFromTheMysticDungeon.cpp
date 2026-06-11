// Last updated: 6/11/2026, 11:18:35 AM
class Solution {
public:
    int maximumEnergy(vector<int>& arr, int k) {
        int n = arr.size();
        int maxen = -1e9;
        vector<int> suff(n, -1e9);
        int maxs = -1e9;
        for(int i=n-1; i>=0; i--){
            if(i+k<n){
                suff[i] = suff[i+k] + arr[i];
            }else{
                suff[i]= arr[i];
            }
            maxs = max(maxs, suff[i]);
        }
        return maxs;
    }
};