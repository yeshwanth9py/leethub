// Last updated: 6/11/2026, 11:23:01 AM
class Solution {
public:
    const long long mod = 1e9+7;
    int totalStrength(vector<int>& arr) {
        long long n = arr.size();
        vector<long long> pref(n, 0);
        vector<long long> spref(n, 0);

        pref[0] = arr[0];
        for(long long i=1; i<n; i++){
            pref[i] = ((pref[i-1] + arr[i])%mod + mod)%mod;
        }

        spref[0] = pref[0];
        for(long long i=1; i<n; i++){
            spref[i] = ((spref[i-1] + pref[i])%mod + mod)%mod;
        }

        vector<long long> prevmin(n, -1);
        stack<long long> st;
        for(long long i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prevmin[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        vector<long long> nextmin(n, n);
        for(long long i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nextmin[i] = st.top();
            }
            st.push(i);
        }
        //(i-l+1)*(spref[r]-spref[i-1]) - (r-i+1)*(spref[i-1]-spref[l-2])
        long long ans = 0;
        for(long long i = 0; i < n; i++){
            long long l = prevmin[i];
            long long r = nextmin[i];
            l++;
            r--;
            long long sumbtw = (spref[r]-(i-1>=0?spref[i-1]:0)+mod)%mod;

            long long cur = (((i-l+1)*(sumbtw))%mod + mod)%mod;
            sumbtw = ((i-1>=0?spref[i-1]:0)-(l-2>=0?spref[l-2]:0)+mod)%mod;

            cur = (cur - ((r-i+1)*(sumbtw))%mod + mod)%mod;

            ans += ((cur*arr[i])%mod + mod)%mod;
            ans = (ans%mod + mod)%mod;
        }

        return ans;
    }
};

