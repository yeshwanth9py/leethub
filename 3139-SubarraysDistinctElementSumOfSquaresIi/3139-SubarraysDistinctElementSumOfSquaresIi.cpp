// Last updated: 6/11/2026, 11:20:01 AM
struct node{
    int lazy = 0;
    long long firstorder = 0;
    long long secondorder = 0;
    node(int x=0){
        lazy = 0;
        firstorder = x;
        secondorder = x*x;
    }
};
long long mod = 1e9+7;
node t[400400];

node merge(node a, node b){
    node ans;
    ans.firstorder = (a.firstorder%mod+b.firstorder%mod)%mod;
    ans.secondorder = (a.secondorder%mod+b.secondorder%mod)%mod;
    return ans;
}

void push(int idx, int l, int r){
    if(t[idx].lazy == 0){
        return;
    }

    //(ai+x)2  = ai2 + x2 + 2.x.(ai);
    //(ai+x) = ai + x*(r-l+1);

    t[idx].secondorder = t[idx].secondorder + (r-l+1)*(t[idx].lazy*t[idx].lazy) + 2*t[idx].lazy*(t[idx].firstorder);
    t[idx].firstorder += (t[idx].lazy)*(r-l+1);

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
        t[idx].lazy += x;
        push(idx, l, r);
        return;
    }

    int mid = (l+r)/2;
    update(2*idx, l, mid, ql, qr, x);
    update(2*idx+1, mid+1, r, ql, qr, x);
    t[idx] = merge(t[2*idx], t[2*idx+1]);
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

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ump;
        long long ans = 0;
        build(1, 0, n-1);
        for(int i=0; i<n; i++){
            int prev = -1;
            if(ump.find(nums[i])!=ump.end()){
                prev = ump[nums[i]];
            }
            update(1, 0, n-1, prev+1, i, 1);
            ans += (t[1].secondorder)%mod;
            ans %= mod;
            ump[nums[i]] = i;
        }
        return ans;
    }
};