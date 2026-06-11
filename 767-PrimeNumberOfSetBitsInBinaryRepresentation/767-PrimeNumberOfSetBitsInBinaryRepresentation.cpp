// Last updated: 6/11/2026, 11:31:24 AM
class Solution {
public:
    string l = "";
    string h = "";
    bool isprime(int num){
        if(num == 1) return 0;
        for(int j=2; j*j<=num; j++){
            if(num%j == 0){
                return 0;
            }
        }
        return 1;
    }
    int rec(int idx, int tlo, int thi, int nop){
        if(idx == l.size()){
            if(isprime(nop)){
                return 1;
            }
            return 0;
        }

        int lo = 0;
        if(tlo == 1){
            lo = l[idx]-'0';
        }

        int hi = 1;
        if(thi == 1){
            hi = h[idx]-'0';
        }


        int ans = 0;
        for(int i=lo; i<=hi; i++){
            int ntlo = tlo;
            if(i != lo){
                ntlo = 0;
            }
            int nthi = thi;
            if(i != hi){
                nthi = 0;
            }
            int nnop = nop;
            if(i == 1){
                nnop = nop+1;
            }
            ans += rec(idx+1, ntlo, nthi, nnop);
        }

        return ans;
    }

    int countPrimeSetBits(int left, int right) {
        for(int i=0; i<=30; i++){
            if(left&(1LL<<i)){
                l.push_back('1');
            }else{
                l.push_back('0');
            }
        }

        reverse(l.begin(), l.end());
        for(int i=0; i<=30; i++){
            if(right&(1LL<<i)){
                h.push_back('1');
            }else{
                h.push_back('0');
            }
        }

        reverse(h.begin(), h.end());

        return rec(0, 1, 1, 0);


    }
};


