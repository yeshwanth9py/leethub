// Last updated: 6/11/2026, 11:27:04 AM
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n = arr.size();
        int cnt = 0;
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(abs(arr[i]-arr[j])<=a && abs(arr[i]-arr[k])<=c && abs(arr[j]-arr[k])<=b){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};