// Last updated: 6/11/2026, 11:11:58 AM
struct Seg{
    vector<long long> t;
    Seg(long long n){
        t.resize(4*n, 0);
    }
    void insert(long long idx, long long l, long long r, long long val){
        if(r<val || l>val) return;
        if(l == r){
             t[idx]++;
             return;
        }  
        long long mid = (l+r)/2;
        insert(2*idx, l, mid, val);
        insert(2*idx+1, mid+1, r, val);
        t[idx] = t[2*idx] + t[2*idx+1];
    }

    void remove(long long idx, long long l, long long r, long long val){
        if(r<val || l>val) return;
        if(l == r){
             t[idx]--;
             return;
        }  
        long long mid = (l+r)/2;
        remove(2*idx, l, mid, val);
        remove(2*idx+1, mid+1, r, val);
        t[idx] = t[2*idx] + t[2*idx+1];
    }
    
    long long queryless(long long idx, long long l, long long r, long long ql, long long qr){
        if(r<ql || qr<l) return 0;
        if(l>=ql && r<=qr){
            return t[idx];
        }
        long long mid = (l+r)/2;
        return queryless(2*idx, l, mid, ql, qr) + queryless(2*idx+1, mid+1, r, ql, qr);
    }

    
};

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        map<long long, long long> ump;
        for(long long el: nums){
            ump[el] = 1;
            ump[el-1] = 1;
        }
        ump[0] = 1;

        long long id = 0;
        for(auto el: ump){
            ump[el.first] = id;
            id++;
        }
        long long m = id;
        Seg sg(m);

        long long ansp = 0;
        for(long long i=0; i<k; i++){
            //count of strictly greater elements are needed, so find <=el and do i-el
            long long gel = (i-sg.queryless(1, 0, m-1, 0, ump[nums[i]]));
            ansp += gel;
            sg.insert(1, 0, m-1, ump[nums[i]]);
        }

        long long minans = ansp;
        long long j=0;
        for(long long i=k; i<nums.size(); i++){
            long long nosm = sg.queryless(1, 0, m-1, 0, ump[nums[j]-1]);
            ansp -= nosm;
            sg.remove(1, 0, m-1, ump[nums[j]]);
            j++;

            long long gel = (k-1-sg.queryless(1, 0, m-1, 0, ump[nums[i]]));
            ansp += gel;
            sg.insert(1, 0, m-1, ump[nums[i]]);
            minans = min(minans, ansp);
        }

        return minans;
        
    }
};




