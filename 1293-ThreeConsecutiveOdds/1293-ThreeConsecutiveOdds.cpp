// Last updated: 6/11/2026, 11:29:01 AM
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()<3) return 0;

        int n = arr.size();
        for(int i=0; i<n-2; i++){
            if(arr[i]%2 == 1 && arr[i+1]%2 == 1 && arr[i+2]%2 == 1){
                return 1;
            }
        }
        return 0;
    }
};