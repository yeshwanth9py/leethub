// Last updated: 6/11/2026, 11:19:44 AM
struct node{
    int sumofxsq = 0;
    int sumofx = 0;
    int lazy = 0;
    node(int lz=0, int sx=0, int ssx = 0){
        sumofxsq = ssx;
        sumofx = sx;
        lazy = lz;
    }
};


node t[401];

vector<int> nums;
int n;

node merge(node a, node b){
    node ans;
    ans.sumofxsq = a.sumofxsq+b.sumofxsq;
    ans.sumofx = a.sumofx+b.sumofx;
    ans.lazy = 0;
    return ans;
}

void build(int idx, int l, int r){
    if(l == r){
        t[idx] = node();
        return;
    }

    int mid = (l+r)/2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    t[idx] = merge(t[2*idx], t[2*idx+1]);
}

void push(int idx, int l, int r){
    if(t[idx].lazy == 0) return;
    
    //(x+r)2 = sumx2 + sumr2 + 2*sum(x, r)
    t[idx].sumofxsq = t[idx].sumofxsq + (r-l+1)*(t[idx].lazy)*(t[idx].lazy) + 2*(t[idx].sumofx)*(t[idx].lazy);
    t[idx].sumofx = t[idx].sumofx + (r-l+1)*t[idx].lazy;
    if(l!=r){
        t[2*idx].lazy += t[idx].lazy;
        t[2*idx+1].lazy += t[idx].lazy;
    }
    t[idx].lazy = 0;
}


void update(int idx, int l, int r, int ql, int qr, int x){
    push(idx, l, r);
    if(qr<l || r<ql){
        return;
    }
    if(ql<=l && r<=qr){
        t[idx].lazy = x;
        push(idx, l, r);
        return;
    }

    int mid = (l+r)/2;
    update(2*idx, l, mid, ql, qr, x);
    update(2*idx+1, mid+1, r, ql, qr, x);
    t[idx] = merge(t[2*idx], t[2*idx+1]);
}


class Solution {
public:
    int sumCounts(vector<int>& num) {
        n = num.size();
        nums = num;
        unordered_map<int, int> ump;
        int ans = 0;
        build(1, 0, n-1);
        
        for(int i=0; i<n; i++){
            int prev = -1;
            if(ump.find(num[i])!=ump.end()){
                prev = ump[num[i]];
            }
            update(1, 0, n-1, prev+1, i, 1);
            ans += t[1].sumofxsq;
            ump[num[i]] = i;
        }
        return ans;
        
    }
};