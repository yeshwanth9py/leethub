// Last updated: 6/11/2026, 11:13:05 AM
struct Seg{
    vector<int> t;
    Seg(long long n){
        t.resize(4*n, 0);
    }

    void insert(long long idx, long long l, long long r, long long pos, long long val){
        if(pos<l || pos>r) return;
        if(l == r){
            t[idx] += val;
            return;
        }
        
        long long mid = (l+r)/2;
        insert(2*idx, l, mid, pos, val);
        insert(2*idx+1, mid+1, r, pos, val);
        t[idx] = (t[2*idx] + t[2*idx+1]);
    }

    long long query(long long idx, long long l, long long r, long long ql, long long qr){
        if(r<ql || qr<l){
            return 0;
        }
        if(ql <= l && r <= qr){
            return t[idx];
        }
        
        long long mid = (l+r)/2;
        return query(2*idx, l, mid, ql, qr) + query(2*idx+1, mid+1, r, ql, qr);
    }
    
};


class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        for(long long i=0; i<nums.size(); i++){
            if(nums[i] == target){
                nums[i] = 1;
            }else{
                nums[i] = -1;
            }
        }

        long long sum = 0;
        long long n = nums.size();
        
        vector<long long> pref(n, 0);
        pref[0] = nums[0];
        
        for(long long i=1; i<n; i++){
            pref[i] = pref[i-1]+nums[i];
        }

        map<long long, long long> mp;
        for(long long el: pref){
            mp[el] = 1;
            mp[el-1] = 1;
        }
        
        mp[0] = 1;
        mp[-1] = 1;

        long long idx = 1;
        for(auto el: mp){
            mp[el.first] = idx;
            idx++;
        }

        long long tot = idx;
        Seg sg(tot+1);
        sg.insert(1, 0, tot, mp[0], 1);
        sum = 0;

        long long ans = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
            int nel = sg.query(1, 0, tot, 0, mp[sum-1]);
            ans += nel;
            sg.insert(1, 0, tot, mp[sum], 1);
        }
        
        
        return ans;
        
    }
};