// Last updated: 6/11/2026, 11:23:27 AM
struct Segment_tree{
    vector<int> t;
    Segment_tree(int n){
        t.resize(4*n, 0);
    }

    void insert(int idx, int sl, int sr, int ind){
        if(ind<sl || ind>sr) return;
        t[idx]++;
        if(sl == sr) return;
        int mid = sl+((sr-sl)/2);
        insert(2*idx+1, sl, mid, ind);
        insert(2*idx+2, mid+1, sr, ind);
    }

    int querysum(int idx, int sl, int sr, int left, int right){
        if(right<sl || sr<left) return 0;
        if(left<=sl && right>=sr){
            return t[idx];
        }
        int mid = sl+(sr-sl)/2;
        return querysum(2*idx+1, sl, mid, left, right)+querysum(2*idx+2, mid+1, sr, left, right);
    }
};


class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        Segment_tree sg(n); 
        unordered_map<int, int> ump;
        for(int i=0; i<n; i++){
            ump[nums2[i]] = i;
        }

        sg.insert(0, 0, n-1, ump[nums1[0]]);
        long long good_tripl = 0;
        for(int j=1; j<n-1; j++){
            long long left_common = sg.querysum(0, 0, n-1, 0, ump[nums1[j]]);
            long long left_uncommon = j-left_common;
            long long right_common = n-ump[nums1[j]]-1-left_uncommon;
            good_tripl += (left_common*right_common);
            sg.insert(0, 0, n-1, ump[nums1[j]]);
        }
        return good_tripl;

    }
};