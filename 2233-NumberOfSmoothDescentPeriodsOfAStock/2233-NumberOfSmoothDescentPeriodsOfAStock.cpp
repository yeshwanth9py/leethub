// Last updated: 6/11/2026, 11:23:54 AM
class Solution {
public:
    long long getDescentPeriods(vector<int>& arr) {
        long long i = 0;
        long long j = -1;
        long long prev = -1;
        long long ans = 0;
        long long n = arr.size();
        while(i<n){
            while(j+1<n && (arr[j+1]==prev-1 || j-i+1 == 0)){
                j++;
                prev = arr[j];
            }

            if(j-i+1>=0){
                long long len = j-i+1;
                ans += ((len)*(len+1))/2;
            }

            if(i>j){
                i++;
                j=i-1;
            }else{
                i=j+1;
            }

        }

        return ans;
    }
};