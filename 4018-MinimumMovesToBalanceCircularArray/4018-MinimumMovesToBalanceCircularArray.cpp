// Last updated: 6/11/2026, 11:13:50 AM
class Solution {
public:
    long long minMoves(vector<int>& arr) {
        long long s = accumulate(arr.begin(), arr.end(), 0LL);
        if(s<0) return -1;
        long long n = arr.size();
        long long idx = min_element(arr.begin(), arr.end()) - arr.begin();
        if(arr[idx]>=0) return 0;

        long long r = (idx+1)%n;
        long long l = (idx-1+n)%n;
        long long rs = abs(arr[idx]);
        long long mv = 0;
        long long num = 1;
        while(rs>0){
            if(arr[l]>=rs){
                arr[l] = 0;
                mv += rs*(num);
                rs = 0;
                break;
            }else{
                mv += arr[l]*num;
                rs -= arr[l];
                arr[l] = 0;
            }
            l= (l-1+n)%n;
            if(rs == 0) break;

            if(arr[r]>=rs){
                arr[r] = 0;
                mv += rs*num;
                rs = 0;
            }else{
                mv += arr[r]*num;
                rs -= arr[r];
                arr[r] = 0;
            }

            r = (r+1)%n;
            num++;
        }

        return mv;

    }
};