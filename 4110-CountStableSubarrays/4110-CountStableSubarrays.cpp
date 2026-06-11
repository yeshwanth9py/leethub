// Last updated: 6/11/2026, 11:12:36 AM
class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        long long n = nums.size();
        long long id = 0;
        unordered_map<long long, pair<long long, long long>> ump;
        unordered_map<long long, long long> umpid;

        long long st = 0;
        for(long long i=0; i<n; i++){
            if(i+1<n && nums[i]<=nums[i+1]){
                umpid[i] = id;
                continue;
            }else{
                ump[id] = {st, i};
                st = i+1;
                umpid[i] = id;
                id++;
            }
        }

        vector<long long> pref(id, 0);
        for(long long i=0; i<id; i++){
            long long r = ump[i].second;
            long long l = ump[i].first;
            pref[i] = ((r-l+1)*(r-l+2))/2;
            if(i){
                pref[i] += pref[i-1];
            }
        }

        vector<long long> ans;
        for(auto q: queries){
            long long l = q[0];
            long long r = q[1];
            if(umpid[l] == umpid[r]){
                long long nos = ((r-l+1)*(r-l+2))/2;
                ans.push_back(nos);
                continue;
            }
            long long lind = umpid[l];
            long long rind = umpid[r];
            long long nos = (rind-1>=0?pref[rind-1]:0)-(lind>=0?pref[lind]:0);
            long long enlind = ump[lind].second;
            nos += ((enlind-l+1)*(enlind-l+2))/2;
            long long strind = ump[rind].first;
            nos += ((r-strind+1)*(r-strind+2))/2;
            ans.push_back(nos);
        }

        return ans;


    }
};