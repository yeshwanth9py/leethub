// Last updated: 6/11/2026, 11:13:32 AM
struct node{
    int min;
    int max;
    int lazy;
    node(int v=1e9, int z = -1e9, int laz = 0){
        min = v;
        max = z;
        lazy = laz;
    }
};

struct Seg{
    vector<node> t;
    Seg(int n, vector<int> &pre){
        t.resize(4*n);
        build(1, 0, n-1, pre);
    }

    node merge(node a, node b){
        node ans;
        ans.min = min(a.min, b.min);
        ans.max = max(a.max, b.max);
        return ans;
    }

    void push(int idx, int l, int r){
        if(t[idx].lazy){
            t[idx].min += t[idx].lazy;
            t[idx].max += t[idx].lazy;
        
            int mid = (l+r)/2;
            if(l!=r){
                t[2*idx].lazy +=  t[idx].lazy;
                t[2*idx+1].lazy += t[idx].lazy;
            }
            t[idx].lazy = 0;
        }
    }

    void build(int idx, int l, int r, vector<int> &pre){
        if(l == r){
            t[idx] = node(pre[l], pre[l], 0);
            return;
        }
        int mid = (l+r)/2;
        build(2*idx, l, mid, pre);
        build(2*idx+1, mid+1, r, pre);
        t[idx] = merge(t[2*idx], t[2*idx+1]);
    }

    void update(int idx, int l, int r, int ql, int qr, int val){
        push(idx, l, r);
        if(qr<l || r<ql){
            return;
        }
        if(ql<=l && r<=qr){
            t[idx].lazy += val;
            push(idx, l, r);
            return;
        }

        int mid = (l+r)/2;
        update(2*idx, l, mid, ql, qr, val);
        update(2*idx+1, mid+1, r, ql, qr, val);
        t[idx] = merge(t[2*idx], t[2*idx+1]);
    }

    int query(int idx, int l, int r, int ql, int qr){
        push(idx, l, r);
        if(qr<l || r<ql){
            return -1;
        }
        if(t[idx].min<=0 && t[idx].max>=0){
            int mid = (l+r)/2;
            int ret = -1;
            if(l == r) return l;
            push(2*idx, l, mid);
            push(2*idx+1, mid+1, r);
            if(t[2*idx+1].min<=0 && t[2*idx+1].max>=0){
                ret = query(2*idx+1, mid+1, r, ql, qr);
            }
            if(ret == -1){
                ret = query(2*idx, l, mid, ql, qr);
            }
            return ret;
        }else{
            return -1;
        }
    }
};


class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ump;
        vector<int> next(n, n);
        for(int i=n-1; i>=0; i--){
            if(ump.find(nums[i])!=ump.end()){
                next[i] = ump[nums[i]];
            }
            ump[nums[i]] = i;
        }

        vector<int> pref(n, 0);
        int cs = 0;
        ump.clear();
        for(int i=0; i<n; i++){
            if(ump.find(nums[i]) != ump.end() || ump[nums[i]]>0){
                pref[i] = cs;
                // cout<<pref[i]<<" ";
                continue;
            }
            ump[nums[i]] = 1;
            int el = ((nums[i]%2 == 0)?1:-1);
            cs += el;
            pref[i] = cs;
            // cout<<pref[i]<<" ";
        }
        // cout<<endl;

        Seg sg(n, pref);

        int ans = sg.query(1, 0, n-1, 0, n-1)+1;
        // cout<<ans<<endl;
        for(int i=1; i<n; i++){
            int pel = nums[i-1];
            int nxt = next[i-1];
            int upd = ((nums[i-1]%2 == 0)?-1:1);
            sg.update(1, 0, n-1, i, nxt-1, upd);
            int curans = sg.query(1, 0, n-1, i, n-1);
            // cout<<curans<<" ";
            if(curans!=-1){
                curans = curans-i+1;
                ans = max(ans, curans);
            }
        }

        return ans;
    }
};