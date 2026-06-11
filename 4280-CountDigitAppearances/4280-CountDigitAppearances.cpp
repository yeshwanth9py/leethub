// Last updated: 6/11/2026, 11:09:34 AM
class Solution {
public:
    int countDigitOccurrences(vector<int>& arr, int d) {
        int cnt = 0;
        for(int el: arr){
            if(d == el && el == 0) cnt++;
            while(el){
                int ld = el%10;
                el  = el/10;
                if(ld == d){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};