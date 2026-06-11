// Last updated: 6/11/2026, 11:17:24 AM
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<int> arr(1e6, 0);
        for(int el: nums){
            arr[el]++;  //storing freq of every elem
        }

        vector<int> pref(1e6, 0);
        pref[0] = arr[0];
        for(int i=1; i<1e6; i++){
            pref[i] = pref[i-1]+arr[i];
        }

        int ans = 1;
        for(int i=0; i<1e5+10; i++){
            int el = i;
            int ebelo = pref[el]-((el-k-1>=0)?pref[el-k-1]:0);  //elems btw el-k and el
            int eabove = pref[el+k] - pref[el];  //elems btw el+1 and el+k;
            int tot = ebelo + eabove;
            // cout<<el<<" "<<tot<<endl;
            int op = tot-arr[el];  //no of operations needed to convert other elems
            if(op>numOperations){  
                ans = max(ans, tot-(op-numOperations));
            }else{
                ans = max(ans, tot);
            }
        }

        return ans;
    }
};