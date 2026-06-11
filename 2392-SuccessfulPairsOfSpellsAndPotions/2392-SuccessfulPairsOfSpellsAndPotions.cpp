// Last updated: 6/11/2026, 11:22:57 AM
class Solution {
public:
    vector<int> successfulPairs(vector<int>& sp, vector<int>& po, long long su) {
        vector<int> asalans;
        sort(po.begin(), po.end());
        for(int i=0; i<sp.size(); i++){
            int val = sp[i];
            int lo = 0;
            int hi = po.size()-1;
            int ans = -1;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(1LL*val*po[mid]>=su){
                    ans = mid;
                    hi = mid-1;
                }else{
                    lo = mid+1;
                }
            }
            // cout<<ans<<" ";
            if(ans == -1){
                asalans.push_back(0);
            }else{
                asalans.push_back(po.size()-ans);
            }
        }

        return asalans;
    }
};