// Last updated: 6/11/2026, 11:31:46 AM
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i=0;
        while(i<n){
            if(i == n-1) return 1;
            if(bits[i] == 1){
                i=i+2;
            }else{
                i++;
            }
        }
        return 0;

    }
};