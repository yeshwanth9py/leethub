// Last updated: 6/11/2026, 11:24:12 AM
class Solution {
public:
    bool isvalid(int mp, int n, vector<int> &quantities){
        int st = 0;
        for(int i=0; i<quantities.size(); i++){
            st += (quantities[i]/mp);
            if(quantities[i]%mp){
                st++;
            }
        }
        return st<=n;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo = 1;
        int hi = *max_element(quantities.begin(), quantities.end());
        int ans = 0;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(isvalid(mid, n, quantities)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        return ans;
    }
};