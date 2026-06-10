struct node{
    long long v;
    long long mx;
    long long mn;
};

struct Seg{
    vector<node> t;
    vector<int> arr;
    Seg(long long n, vector<int> &brr){
        t.resize(4*n);
        arr = brr;
        build(1, 0, n-1);
    }

    node merge(node a, node b){
        node c;
        c.mx = max(a.mx, b.mx);
        c.mn = min(a.mn, b.mn);
        c.v = c.mx - c.mn;
        return c;
    }

    void build(long long ind, long long l, long long r){
        if(l == r){
            t[ind].mx = arr[l];
            t[ind].mn = arr[l];
            t[ind].v = 0;
            return;
        }
        long long mid = (l+r)/2;
        build(2*ind, l, mid);
        build(2*ind+1, mid+1, r);
        t[ind] = merge(t[2*ind], t[2*ind+1]);
    }
    node query(long long ind, long long l, long long r, long long ql, long long qr){
        if(r<ql || qr<l){
            return node(0, -1e9, 1e9);
        }
        if(ql<=l && r<=qr){
            return t[ind];
        }
        long long mid = (l+r)/2;
        return merge(query(2*ind, l, mid, ql, qr), query(2*ind+1, mid+1, r, ql, qr));
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, long long k) {
        long long n = nums.size();
        map<pair<long long, long long>, long long> vis;
        priority_queue<vector<long long>> pq;
        long long mx = *max_element(nums.begin(), nums.end());
        long long mn = *min_element(nums.begin(), nums.end());

        pq.push({mx-mn, 0, n-1});
        long long tak = 0;
        Seg sg(n, nums);
        long long sum = 0;

        while(!pq.empty()){
            auto tel = pq.top(); pq.pop();
            long long v = tel[0];
            long long i = tel[1];
            long long j = tel[2];
            vis[{i, j}] = 1;

            tak++;
            sum += v;
            if(tak>=k) return sum;
            if(i+1<=j && vis.find({i+1, j}) == vis.end()){
                vis[{i+1, j}] = 1;
                long long v1 = sg.query(1, 0, n-1, i+1, j).v;
                pq.push({v1, i+1, j});
            }

            if(i<=j-1 && vis.find({i, j-1}) == vis.end()){
                vis[{i, j-1}] = 1;
                long long v2 = sg.query(1, 0, n-1, i, j-1).v;
                pq.push({v2, i, j-1});
            }
        }

        return sum;
    }
};