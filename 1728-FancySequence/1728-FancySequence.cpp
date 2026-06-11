// Last updated: 6/11/2026, 11:26:46 AM
//x*m + inc -> (x*m + inc)*m2 ->x*m*m2 + inc*m2;
//(x+inc)*m -> xm + m*inc -> 

const int mod = 1e9+7;
struct node{
    int incr;
    int mult;
    int val;
    node(){
        incr = 0;
        mult = 1;
        val = 0;
    }
};

struct Seg{
    vector<node> t;
    Seg(long long n){
        t.resize(4*n);
    }

    void push(long long idx, long long l, long long r){
        if(t[idx].incr != 0 || t[idx].mult != 1){
            if(l==r){
                t[idx].val = (((1LL*t[idx].val*t[idx].mult)%mod + t[idx].incr)%mod + mod)%mod;
            }else{
                if(t[2*idx].incr == 0 && t[2*idx].mult == 1){
                    t[2*idx].incr = t[idx].incr%mod;
                    t[2*idx].mult = t[idx].mult%mod;
                }else{
                    //(x*m + b)*m2 = x*m*m2 + b*m2 +x 
                    t[2*idx].mult =  (1LL*t[2*idx].mult*t[idx].mult)%mod;
                    t[2*idx].mult = (t[2*idx].mult%mod + mod)%mod;

                    t[2*idx].incr = (1LL*t[2*idx].incr*t[idx].mult)%mod + t[idx].incr;
                    t[2*idx].incr = (t[2*idx].incr%mod + mod)%mod;
                }

                if(t[2*idx+1].incr == 0 && t[2*idx+1].mult == 1){
                    t[2*idx+1].incr = t[idx].incr;
                    t[2*idx+1].mult = t[idx].mult;
                }else{
                    t[2*idx+1].mult = (1LL*t[2*idx+1].mult*t[idx].mult)%mod;
                    t[2*idx+1].mult = (t[2*idx+1].mult%mod + mod)%mod;

                    t[2*idx+1].incr = (1LL*t[2*idx+1].incr*t[idx].mult)%mod + t[idx].incr;
                    t[2*idx+1].incr = (t[2*idx+1].incr%mod + mod)%mod;
                }
            }
            t[idx].incr = 0;
            t[idx].mult = 1;
        }
    }
    
    void addall(long long idx, long long l, long long r, long long ql, long long qr, long long v){
        push(idx, l, r);
        if(r<ql || qr<l) return;
        if(ql<=l && r<=qr){
            t[idx].incr = v;
            push(idx, l, r);
            return;
        }
        long long mid = (l+r)/2;
        addall(2*idx, l, mid, ql, qr, v);
        addall(2*idx+1, mid+1, r, ql, qr, v);
    }

    void multall(long long idx, long long l, long long r, long long ql, long long qr, long long v){
        push(idx, l, r);
        if(r<ql || qr<l) return;
        if(ql<=l && r<=qr){
            t[idx].mult = v;
            push(idx, l, r);
            return;
        }
        long long mid = (l+r)/2;
        multall(2*idx, l, mid, ql, qr, v);
        multall(2*idx+1, mid+1, r, ql, qr, v);
    }

    long long query(long long idx, long long l, long long r, long long pos){
        push(idx, l, r);
        if(pos<l || pos>r) return 0;
        if(l == r){
            return t[idx].val;
        }
        long long mid = (l+r)/2;
        return query(2*idx, l, mid, pos) + query(2*idx+1, mid+1, r, pos);
    }
};

class Fancy {
public:
    Seg* sg;
    long long m;
    long long idx;
    Fancy() {
        m = 1e5+4;
        sg = new Seg(m);
        idx = -1;
    }
    
    void append(int val) {
        idx++;
        sg->addall(1, 0, m-1, idx, idx, val);
    }
    
    void addAll(int inc) {
        sg->addall(1, 0, m-1, 0, idx, inc);
    }
    
    void multAll(int mm) {
        sg->multall(1, 0, m-1, 0, idx, mm);
    }
    
    long long getIndex(long long askidx) {
        if(askidx>idx) return -1;
        return sg->query(1, 0, m-1, askidx);
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * long long param_4 = obj->getIndex(idx);
 */