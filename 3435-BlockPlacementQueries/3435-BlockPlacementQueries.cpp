// Last updated: 6/11/2026, 11:18:17 AM
struct node{
    int leftl;
    int rightl;
    int totl;
    int maxl;
    node(int v = 0){
        leftl = rightl = maxl = totl = v;
    }
};

struct Seg{
    vector<node> t;
    Seg(int n){
        t.resize(4*n);
    }

    node merge(node a, node b){
        node c;
        c.totl = a.totl+b.totl;
        
        c.leftl = a.leftl;

        if(a.leftl == a.totl){
            c.leftl += b.leftl;
        }

        c.rightl = b.rightl;
        if(b.rightl == b.totl){
            c.rightl += a.rightl;
        }

        c.maxl = max({a.maxl, b.maxl, c.leftl, c.rightl, a.rightl+b.leftl});

        return c;
    }

    void build(int idx, int l, int r){
        if(l == r){
            t[idx] = node(r-l+1);
            return;
        }
        int mid = (l+r)/2;
        build(2*idx, l, mid);
        build(2*idx+1, mid+1, r);
        t[idx] = merge(t[2*idx], t[2*idx+1]);
    }

    void update(int idx, int l, int r, int pos){
        if(pos<l || pos>r){
            return;
        }
        if(l == r){
            t[idx].leftl = t[idx].rightl = t[idx].maxl = 0;
            return;
        }
        int mid = (l+r)/2;
        update(2*idx, l, mid, pos);
        update(2*idx+1, mid+1, r, pos);
        t[idx] = merge(t[2*idx], t[2*idx+1]);
    }

    node query(int idx, int l, int r,  int ql, int qr){
        if(qr<l || r<ql){
            return node(0);
        }
        if(l>=ql && r<=qr){
            return t[idx];
        }
        int mid = (l+r)/2;
        return merge(query(2*idx, l, mid, ql, qr), query(2*idx+1, mid+1, r, ql, qr));
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& que) {
        Seg sg(5e4+5);
        int mx = 5e4+5;
        sg.build(1, 0, mx-1);
        sg.update(1, 0, mx-1, 0);

        vector<bool> ans;
        for(auto el: que){
            int sq = el[0];
            int x = el[1];
            if(sq == 1){
                sg.update(1, 0, mx-1, x);
            }else{
                int maxavail = sg.query(1, 0, mx-1, 0, x-1).maxl+1;
                // cout<<maxavail<<" ";
                int szg = el[2];
                if(szg<=maxavail){
                    ans.push_back(1);
                }else{
                    ans.push_back(0);
                }
            }
        }
        
        return ans;
    }

};







