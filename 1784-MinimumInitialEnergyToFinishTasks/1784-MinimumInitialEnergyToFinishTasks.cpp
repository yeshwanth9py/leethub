// Last updated: 6/11/2026, 11:26:38 AM
class Solution {
public:
    int minimumEffort(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), [&](vector<int> &a1, vector<int> &a2){
            return max(a1[1], a1[0]+a2[1]) < max(a2[1], a2[0]+a1[1]);
        });

        auto check = [&](int md){
            int tot = md;
            for(int i=0; i<arr.size(); i++){
                if(arr[i][1]<=tot){
                    tot -= arr[i][0];
                }else{
                    return 0;
                }
            }

            return 1;
        };

        int lo = 0;
        int hi = 1e9;
        int ans = -1;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid)){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }

        while(1){
            if(check(ans-1)){
                ans = ans - 1;
            }else{
                break;
            }
        }

        return ans;



    }
};