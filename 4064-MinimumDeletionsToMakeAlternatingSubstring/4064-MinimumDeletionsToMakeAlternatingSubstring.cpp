// Last updated: 6/11/2026, 11:13:17 AM
struct Seg{
    int n;
    vector<int> t;
    vector<int> arr;
    Seg(vector<int> &arr){
        n = arr.size();
        this->arr = arr;
        t.resize(4*n, 0);
        build(1, 0, n-1);
    }

    void build(int idx, int l, int r){
        if(l == r){
            t[idx] = arr[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*idx, l, mid);
        build(2*idx+1, mid+1, r);
        t[idx] = t[2*idx]+t[2*idx+1];
    }

    void update(int idx, int l, int r, int pos, int val){
        if(pos<l || pos>r) return;
        if(l == r){
            t[idx] = val;
            return;
        }
        int mid = (l+r)/2;
        update(2*idx, l, mid, pos, val);
        update(2*idx+1, mid+1, r, pos, val);
        t[idx] = t[2*idx]+t[2*idx+1];
    }

    int querysum(int idx, int l, int r, int ql, int qr){
        if(r<ql || qr<l) return 0;
        if(l>=ql && r<=qr) return t[idx];
        int mid = (l+r)/2;
        return querysum(2*idx, l, mid, ql, qr) + querysum(2*idx+1, mid+1, r, ql, qr);
    }
};


class Solution {
public:
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> arr(n, 0);
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1]){
                arr[i] = 1;
            }
        }

        vector<int> ans;
        Seg sg(arr);
        for(auto q: queries){
            if(q[0] == 1){
                int idx = q[1];
                arr[idx] = !arr[idx];
                if(idx+1<n) arr[idx+1] = !arr[idx+1];
                sg.update(1, 0, n-1, idx, arr[idx]);
                if(idx+1<n) sg.update(1, 0, n-1, idx+1, arr[idx+1]);
            }else{
                int l = q[1];
                int r = q[2];
                if(l == r){
                    ans.push_back(0);
                    continue;
                }
                ans.push_back(sg.querysum(1, 0, n-1, l+1, r));
            }
        }

        return ans;
        
    }
};