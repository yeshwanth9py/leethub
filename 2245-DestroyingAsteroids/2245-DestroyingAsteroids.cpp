// Last updated: 6/11/2026, 11:23:48 AM
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long long m = mass;
        for(int el: arr){
            if(el>m) return 0;
            m += el;
        }
        return 1;
    }
};