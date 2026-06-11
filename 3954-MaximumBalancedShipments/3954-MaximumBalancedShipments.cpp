// Last updated: 6/11/2026, 11:14:30 AM
class Solution {
public:
    int maxBalancedShipments(vector<int>& arr) {
        long long n = arr.size();
        long long maxtn = 1e18;
        long long mintn = 1e18;
        long long cnt = 0;
        for(long long i=0; i<n; i++){
            if(maxtn == 1e18){
                maxtn = arr[i];
                // mintn = arr[i];
            }else{
                if(arr[i]<maxtn){
                    maxtn = 1e18;
                    cnt++;
                }else{
                    maxtn = max(maxtn, 1LL*arr[i]);
                }
            }
        }

        return cnt;

        
        //lds??
        // vector<long long> lds;
        // for(int i=0; i<n; i++){
        //     if((lds.size() == 0) || weight[i]<lds.back()){
        //         lds.push_back(weight[i]);
        //     }else{
        //         int wt = weight[i];
        //         int idx = -1;
        //         int lo = 0;
        //         int hi = lds.size()-1;
        //         while(lo<=hi){
        //             int mid = (lo+hi)/2;
        //             if(lds[mid]<=wt){
        //                 idx = mid;
        //                 hi = mid-1;
        //             }else{
        //                 lo=mid+1;
        //             }
        //         }
        //         if(idx == -1){
        //             lds.push_back(wt);
        //         }else{
        //             lds[idx] = wt;
        //         }
        //     }
        // }

        // for(int el: lds){
        //     cout<<el<<" ";
        // }
        // cout<<endl;

        // return lds.size()-1;
    }
};