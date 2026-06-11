// Last updated: 6/11/2026, 11:22:12 AM
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        // reverse(nums.begin(), nums.end());
        vector<int> maxorpos(n, 0);
        maxorpos[n-1] = nums[n-1];

        for(int i=n-2; i>=0; i--){
            maxorpos[i] = (maxorpos[i+1] | nums[i]);
        }

        vector<int> ans(n, 1);
        int i=0;
        int j=-1;
        vector<int> cur(30, 0);
        int curnum = 0;

        // for(int i=0; i<30; i++){
        //     if((nums[i] & (1LL<<i))){
        //         cur[i] = 1;
        //     }
        // }

        while(i<n){
            while(j+1<n && maxorpos[i] != curnum){
                j++;
                for(int d=0; d<30; d++){
                    if((nums[j] & (1LL<<d))){
                        cur[d]++;
                    }
                }
                curnum |= nums[j];
                if(curnum == maxorpos[i]){
                    break;
                }
            }

            if(j-i+1>0){
                ans[i] = (j-i+1); 
            }

            for(int d=0; d<30; d++){
                if((nums[i] & (1LL<<d))){
                    cur[d] -= 1;
                    if(cur[d] == 0){
                        curnum = curnum & (~(1LL<<d));
                    }
                }
            }
            i++;
        }


        return ans;


    }
};