// Last updated: 6/11/2026, 11:28:13 AM
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int a = 1;
        int b = n-1;
        while(a<=b){
            //10 power 4 so max 4 numbers only
            int temp1 = a;
            int temp2 = b;
            bool fl = 1;
            while(temp1){
                int ld = temp1%10;
                if(ld == 0){
                    fl = 0;
                    break;
                }
                temp1 = temp1/10;
            }
            while(temp2){
                int ld = temp2%10;
                if(ld == 0){
                    fl = 0;
                    break;
                }
                temp2 = temp2/10;
            }
            if(fl){
                return {a, b};
            }
            a++;
            b--;
        }

        return {-1, -1};
    }
};