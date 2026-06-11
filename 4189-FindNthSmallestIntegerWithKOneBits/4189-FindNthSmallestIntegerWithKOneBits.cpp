// Last updated: 6/11/2026, 11:10:52 AM
#define ll long long
class Solution {
public:
    ll ncr(ll n, ll r){
        ll num = 1;
        ll den = 1;
        ll ans = 1;
        for(ll i=1; i<=r; i++){
            num = (n-i+1);
            den = i;
            ans = (ans*num)/den;
        }

        return ans;
    }

    long long nthSmallest(long long n, ll k) {
        ll num = (1LL<<k)-1;
        // cout<<bitset<5>(num)<<endl;
        //k-1 1s needed btw 1LL<<(k+1)-1 to (1LL<<k)-1;
        if(n == 1) return num;
        ll avail = k-1;
        ll ans = 0;
        while(k>0){
            // cout<<n<<": ";
            // if(n==1){
            //     ans |= ((1LL << k) - 1); // Only add k bits, not avail+1 bits
            //     return ans;
            // }
            ll nextnum = num*2+1;
            
            ll btw = ncr(avail, k-1);
            // cout<<bitset<5>(nextnum)<<" "<<btw<<endl; 
            if(btw<n){
                n -= btw;
                num = nextnum;
                avail++;
            }else{
                ans |= (1LL<<(avail));
                // cout<<"ans: "<<bitset<5>(ans)<<endl;
                k=k-1;
                // cout<<"k: "<<k<<" "; 
                num = (1LL<<k)-1;
                // cout<<"num: "<<bitset<5>(num)<<endl;
                avail = k-1;
            }
        }

        return ans;
        

        
    }
};