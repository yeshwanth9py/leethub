// Last updated: 6/11/2026, 11:33:54 AM
class SegmentTree{
    public:
        vector<int> t;
        SegmentTree(){
            t.clear();
        }
        SegmentTree(int n){
            t.resize(4*n+1);
        }

        void build(int ind, int low, int high, vector<int> &nums){
            if(low == high){
                t[ind] = nums[low];
                return;
            }

            int mid = (low+high)/2;
            build(2*ind+1, low, mid, nums);
            build(2*ind+2, mid+1, high, nums);
            t[ind] = t[2*ind+1]+t[2*ind+2];
        }

        void update(int ind, int low, int high, int key, int val){
            if(low == high){
                t[ind] = val;
                return;
            }
            if(key<low || high<key){
                return;
            }

            int mid = low + (high-low)/2;
            if(key<=mid){
                update(2*ind+1, low, mid, key, val);
            }else{
                update(2*ind+2, mid+1, high, key, val);
            }
            t[ind] = t[2*ind+1]+t[2*ind+2];
        }

        int query(int ind, int low, int high, int l, int r){
            // l low high r
            if(l>high || r<low){
                return 0;
            }
            if(high<=r && low >= l){
                return t[ind];
            }
            int mid = (low+high)/2;
            return query(2*ind+1, low, mid, l, r)+query(2*ind+2, mid+1, high, l, r);
        }
};

class NumArray {
public:
    SegmentTree st;
    vector<int> bnums;
    NumArray(vector<int>& nums) {
        this->bnums = nums;
        st.t.resize(4*bnums.size()+1);
        st.build(0, 0, bnums.size()-1, bnums);
    }
    
    void update(int index, int val) {
        index;
        bnums[index] = val;
        st.update(0, 0, bnums.size()-1, index, val);
    }
    
    int sumRange(int left, int right) {
        int ans =  st.query(0, 0, bnums.size()-1, left, right);
        // if(ans == 0){
        //     return -1;
        // }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */