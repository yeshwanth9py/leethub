// Last updated: 6/11/2026, 11:35:54 AM
class Solution {
    public int singleNumber(int[] nums) {
        int ans = 0;

        for(int i=0; i<32; i++){
            int cnt = 0;
            for(int el: nums){
                if((el&(1<<i)) != 0){
                    cnt++;
                }
            }
            cnt %= 3;
            if(cnt>0){
                ans |= (1<<i);
            }
        }

        return ans;


    }
}