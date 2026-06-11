// Last updated: 6/11/2026, 11:19:24 AM
class Solution {
public:
    int getmaxclen(vector<int> &arr){
        int prev = -1;
        int cur = 0;
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == prev+1){
                cur++;
            }else{
                cur = 1;
            }
            ans = max(ans, cur);
            prev = arr[i];
        }

        return ans+1;
    }

    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());

        int l1 = getmaxclen(h);
        int l2 = getmaxclen(v);

        return min(l1, l2)*min(l1, l2);
        
    }
};