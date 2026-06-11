// Last updated: 6/11/2026, 11:33:58 AM
class NumArray {
public:
    vector<int> prefix;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        prefix.resize(n, 0);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right] - ((left-1>=0)?prefix[left-1]:0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */