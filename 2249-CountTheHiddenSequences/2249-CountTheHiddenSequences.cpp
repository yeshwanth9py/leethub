// Last updated: 6/11/2026, 11:23:45 AM
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long maxr = 0;
        long long minr = 0;
        long long psum = 0;
        for(int el: differences){
            psum += el;
            maxr = max(maxr, psum);
            minr = min(minr, psum);
        } 

        // lower<= minr+x , maxr+x <= upper;
        return max(0ll, upper-maxr-(lower-minr)+1ll);
    }
};