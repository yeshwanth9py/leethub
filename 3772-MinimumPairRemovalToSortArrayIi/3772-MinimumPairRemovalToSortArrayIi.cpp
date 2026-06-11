// Last updated: 6/11/2026, 11:16:06 AM
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> prev(n, 0);
        vector<long long> next(n, 0);

        for(long long i=0; i<n; i++){
            prev[i] = i-1;
            next[i] = i+1;
        }

        vector<long long> temp(n, 0);

        multiset<pair<long long, long long>> ms1;

        long long badp = 0;
        for(long long i=0; i<n; i++){
            temp[i] = nums[i];
            if(i+1<n) ms1.insert({nums[i]+nums[i+1], i});
            if(i+1<n){
                if(nums[i]>nums[i+1]){
                    badp++;
                }
            }
        }



        long long op = 0;
        while(ms1.size()>0 && badp>0){
            auto [sm, idx] = *ms1.begin(); 
            ms1.erase(ms1.begin());

           
            if(temp[idx]>temp[next[idx]]){
                badp--;
            }

            if(prev[idx]!=-1){
                long long pv1 = temp[prev[idx]]+temp[idx];
                if(temp[prev[idx]] > temp[idx]){
                    badp--;
                }
                ms1.erase({pv1, prev[idx]});
                long long nv1 = temp[prev[idx]] + sm;

                if(temp[prev[idx]] > sm){
                    badp++;
                }

                ms1.insert({nv1, prev[idx]});
            }



            long long nid = next[next[idx]];

            if(nid<n){
                long long pv2 = temp[next[idx]] + temp[nid];

                if(temp[next[idx]] > temp[nid]){
                    badp--;
                }

                ms1.erase({pv2, next[idx]});

                ms1.insert({sm+temp[nid], idx});

                if(sm > temp[nid]){
                    badp++;
                }
            }

            
            temp[idx] = sm;

            if(nid<n) prev[nid] = idx;
            next[idx] = nid;
            op++;
        }

        return op;

    }
};