// Last updated: 6/11/2026, 11:24:20 AM
class Solution {
public:
    int isgood(int num){
        unordered_map<int, int> ump;
        while(num){
            int ld = num%10;
            if(ld == 0) return 0;
            ump[ld]++;
            num = num/10;
        }
        for(auto el: ump){
            if(el.first != el.second) return 0;
        }
        return 1;
    }
    int nextBeautifulNumber(int n) {
        if(n == 0) return 1;
        for(int i=n+1; i<1e7; i++){
            if(isgood(i)) return i;
        }
        return n;
    }
};