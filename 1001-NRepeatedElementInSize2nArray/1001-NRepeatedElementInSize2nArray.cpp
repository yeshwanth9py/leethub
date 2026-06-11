// Last updated: 6/11/2026, 11:30:07 AM
class Solution {
public:
    int repeatedNTimes(vector<int>& arr) {
        int n = arr.size();
        for(int i=0; i<n-2; i++){
            if(arr[i] == arr[i+1] || arr[i] == arr[i+2]){
                return arr[i];
            }
        }

        return arr[n-1];

    }
};