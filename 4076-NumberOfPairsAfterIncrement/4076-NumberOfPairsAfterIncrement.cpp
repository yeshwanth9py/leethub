// Last updated: 6/11/2026, 11:13:04 AM
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& que) {
        int n = nums2.size();
        vector<long long> nums(n, 0);
        for(int i=0; i<n; i++) nums[i] = nums2[i];

        int bs = 250;
        int nob = ceil((1.0*n)/bs);

        vector<unordered_map<int, int>> arr(nob, unordered_map<int, int>());
        vector<long long> lazy(nob, 0);

        for(int i=0; i<n; i++){
            int b = i/bs;
            arr[b][nums[i]]++;
        }

        vector<int> op;

        for(auto q: que){
            int ty = q[0];
            
            if(ty == 1){
                int x = q[1];
                int y = q[2];
                int val = q[3];

                int bstart = x/bs;
                int bend = y/bs;

                if(bstart == bend){
                    for(int i=x; i<=y; i++){
                        arr[bstart][nums[i]]--;
                        nums[i] += val;
                        arr[bstart][nums[i]]++;
                    }
                }else{
                    int fbe = (bstart+1)*bs - 1;
                    for(int i=x; i<=fbe; i++){
                        arr[bstart][nums[i]]--;
                        nums[i] += val;
                        arr[bstart][nums[i]]++;
                    }

                    for(int mb = bstart+1; mb<bend; mb++){
                        lazy[mb] += val;
                    }

                    int lbs = (bend)*bs;
                    for(int i=lbs; i<=y; i++){
                        arr[bend][nums[i]]--;
                        nums[i] += val;
                        arr[bend][nums[i]]++;
                    }
                }
            }else{
                int tot = q[1];

                int bstart = 0;
                int bend = nob-1;
                int curans = 0;
                for(int el: nums1){
                    int req = tot - el;

                    for(int i=bstart; i<=bend; i++){
                        int sch = req-lazy[i];
                        auto it = arr[i].find(sch);
                        if(it != arr[i].end()) curans += arr[i][sch];
                    }
                }

                op.push_back(curans);
            }
        }

        return op;
    }
};