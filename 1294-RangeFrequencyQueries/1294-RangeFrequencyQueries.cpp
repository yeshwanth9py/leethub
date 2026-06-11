// Last updated: 6/11/2026, 11:29:00 AM
//learn the 2 methods
//1 - unordered_map which stores the indexes of the value
//then applying upper_bound and lower_bound on it to find the freq of a value in range l to r

//2 - use a segment tree to store the unordered_maps as nodes which will store each key and its frequency

class SegmentTree{
    public:
        vector<unordered_map<int, int>> t;
        SegmentTree(int n){
            t.resize(4*n+1);
        }
        SegmentTree(){
            
        }

        void merge(int ind){
            for(auto el: t[2*ind+1]){
                if(t[ind].find(el.first)==t[ind].end()){
                    t[ind][el.first] = el.second;
                }else{
                    t[ind][el.first] += el.second;
                }
            }

            for(auto el: t[2*ind+2]){
                if(t[ind].find(el.first)==t[ind].end()){
                    t[ind][el.first] = el.second;
                }else{
                    t[ind][el.first] += el.second;
                }
            }
        }

        void build(int ind, int low, int high, vector<int> &arr){
            if(low == high){
                if(t[ind].find(arr[low])==t[ind].end()){
                    t[ind][arr[low]] = 1;
                    return;
                }
                t[ind][arr[low]] += 1;
                return;
            }
            int mid = (low+high)/2;
            build(2*ind+1, low, mid, arr);
            build(2*ind+2, mid+1, high, arr);

            merge(ind);

        }

        int query(int ind, int low, int high, int l, int r, int val){
            if(r<low || l>high){
                return 0;
            }
            if(low>=l && r>=high){
                if(t[ind].find(val) == t[ind].end()){
                    return 0;
                }
                return t[ind][val];
            }
            int mid = (low+high)/2;
            return query(2*ind+1, low, mid, l, r, val)+query(2*ind+2, mid+1, high, l, r, val);
        }
};

class RangeFreqQuery {
public:
    vector<int> arr;
    SegmentTree s;
    RangeFreqQuery(vector<int>& arr) {
        this->arr = arr;
        s.t.resize(4*arr.size()+1);
        s.build(0, 0, arr.size()-1, arr);
    }
    
    int query(int left, int right, int value) {
        return s.query(0, 0, arr.size()-1, left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */