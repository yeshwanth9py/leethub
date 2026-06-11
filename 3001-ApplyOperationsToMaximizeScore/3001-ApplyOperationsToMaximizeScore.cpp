// Last updated: 6/11/2026, 11:20:28 AM
using ll = long long;
ll mod = 1e9 + 7; 

class Solution {
public:
    vector<int> prime;

    void factors() {
        prime.resize(100101, 0); 
        for (int i = 2; i <= 100001; i++) {
            if (prime[i] == 0) {
                for (int j = i; j <= 100001; j += i) {
                    prime[j]++; 
                }
            }
        }
    }

    ll modpow(ll x, ll n, ll mod){
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x%mod;
        }

        if(n%2 == 0){
            ll ans = modpow(x, n/2, mod)%mod;
            return (ans*ans)%mod;
        }else{
            ll ans = ((x%mod)*(modpow(x, (n-1), mod)%mod))%mod;
            return ans;
        }
    }

    int maximumScore(vector<int>& nums, int k) {
        factors();
        vector<int> primesc;
        int n = nums.size();
        for (int el : nums) {
            primesc.push_back(prime[el]);
        }
        // cout << endl;

        stack<int> st;
        vector<int> prevgrt(n, -1);
        st.push(0); 
        for (int i = 1; i < n; i++) {
            while (!st.empty() && primesc[st.top()] < primesc[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prevgrt[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty()) {
            st.pop();
        }

        vector<int> nextgrt(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && primesc[st.top()] <= primesc[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nextgrt[i] = st.top();
            }
            st.push(i);
        }


        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        ll x = 1;
        ll rem = k;
        while (rem) {
            auto mel = pq.top();
            int cel = mel.first;
            int cind = mel.second;
            pq.pop();

            ll left = cind - prevgrt[cind];
            ll right = nextgrt[cind] - cind;

            ll curcnt = min(left * right, rem);
           
            rem -= curcnt;

            x = (x * modpow(cel, curcnt, mod)) % mod; 
        }

        return x;
    }
};