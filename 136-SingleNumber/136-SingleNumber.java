// Last updated: 6/11/2026, 11:35:55 AM
class Solution {
    public int singleNumber(int[] nums) {
        int xorr = 0;

        for(int el: nums){
            xorr ^= el;
        }

        return xorr;
    }
}