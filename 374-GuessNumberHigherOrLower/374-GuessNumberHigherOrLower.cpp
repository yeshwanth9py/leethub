// Last updated: 6/11/2026, 11:33:31 AM
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1;
        int hi = n;
        while(lo<=hi){
            int mid = (lo+((hi-lo)/2));
            if(guess(mid) == 0){
                return mid;
            }else if(guess(mid)>0){
                lo = mid+1;
            }else{
                hi=mid-1;
            }
        }

        return -1;
    }
};