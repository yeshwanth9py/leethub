// Last updated: 6/11/2026, 11:10:31 AM




struct Seg{
    vector<int> t;
    vector<int> arr;
    int n;
    Seg(int n, vector<int> &num){
        t.resize(4*n);
        this->n = n;
        arr = num;
        build(1, 0, n-1);
    }

    int merge(int a, int b){
       return __gcd(a, b);
    }

    void build(int idx, int l, int r){
        if(l == r){
            t[idx] = arr[l];
            return;
        }

        int mid = (l+r)/2;
        build(2*idx, l, mid);
        build(2*idx+1, mid+1, r);
        t[idx] = merge(t[2*idx], t[2*idx+1]);
    }

    void update(int idx, int l, int r, int pos, int v){
        if(pos<l || pos>r) return;
        if(l == r){
            t[idx] = v;
            return;
        }

        int mid = (l+r)/2;
        update(2*idx, l, mid, pos, v);
        update(2*idx+1, mid+1, r, pos, v);
        t[idx] = merge(t[2*idx], t[2*idx+1]);
    }


    bool seg_moon_walk(int idx, int l, int r, int outside_gcd){
        if(outside_gcd == 1) return 1;
        if(l == r) return outside_gcd == 1;
        int mid = (l+r)/2;
        int leftg = seg_moon_walk(2*idx, l, mid, __gcd(outside_gcd, t[2*idx+1]));
        int rightg = seg_moon_walk(2*idx+1, mid+1, r, __gcd(outside_gcd, t[2*idx]));
        return leftg || rightg;
    }
};

class Solution {
public:
    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& que) {
        int n = nums.size();
        int nonz = 0;
        for(int &el: nums){
            if(el%p == 0){
                el = el/p;
                nonz++;
            }else{
                el = 0;
            }
        }

        Seg sg(n, nums);
        int cnt = 0;
        for(auto q: que){
            int idx = q[0];
            int v = q[1];
            if(nums[idx]>0){
                nonz--;
            }
            if(v%p == 0){
                v = v/p;
                nonz++;
            }else{
                v = 0;
            }
            nums[idx] = v;
            sg.update(1, 0, n-1, idx, v);
            int ans = (sg.t[2] == 1) || (sg.t[3] == 1);
            if(ans){
                cnt++;
            }else if(sg.t[1] == 1){
                if(nonz < n){
                    cnt++;
                }else{
                    if(sg.seg_moon_walk(1, 0, n-1, 0)){
                        cnt++;
                    }
                }
            }
        }

        // cout<<__gcd(3, 4)<<endl;

        return cnt;

    }   
};



