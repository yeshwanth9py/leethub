// Last updated: 6/11/2026, 11:26:32 AM
class Solution {
public:
    
    int minMoves(vector<int>& nums, int limit) {
        int mx = 2*limit + 5;

        vector<int> arr(mx, 0);
        
        int n = nums.size();

        unordered_map<int, int> ump;
        for(int i=0; i<(n/2); i++){
            int cv = nums[i] + nums[n-i-1];
            ump[cv]++; 

            // int s1 = nums[i]+1;
            // int e1 = nums[i]+limit;

            // int s2 = nums[n-i-1] + 1;
            // int e2 = nums[n-i-1] + limit;

            // if(s2<s1){
            //     swap(s1, s2);
            //     swap(e1, e2);
            // }

            // if(e1<s2){
            //     arr[s1]++;
            //     arr[e1+1]--;
            //     if(cv>=s1 && cv<=e1){
            //         arr[cv]--;
            //         arr[cv+1]++;
            //     }

            //     arr[s2]++;
            //     arr[e2+1]--;
            //     if(cv>=s2 && cv<=e2){
            //         arr[cv]--;
            //         arr[cv+1]++;
            //     }
            // }else{
            //     int end = max(e1, e2);
            //     arr[s1]++;
            //     arr[end+1]--;
            //     if(cv>=s1 && cv<=end){
            //         arr[cv]--;
            //         arr[cv+1]++;
            //     }
            // }
            int s1 = min(nums[i], nums[n-i-1])+1;
            int e1 = max(nums[i], nums[n-i-1])+limit;
            arr[s1]++;
            arr[e1+1]--;
            if(cv>=s1 && cv<=e1){
                arr[cv]--;
                arr[cv+1]++;
            }
        }

        for(int i=1; i<mx; i++){
            arr[i] += arr[i-1];
        }

        int mov = 1e9;

        for(int sum = 2; sum<=2*limit; sum++){
            int rem = (n/2) - ump[sum];

            int ones = arr[sum];
            int twos = rem-ones;
            int curmov = ones + 2*twos;
            mov = min(mov, curmov);
        }

        return mov;
    }
};