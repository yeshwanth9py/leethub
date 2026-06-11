// Last updated: 6/11/2026, 11:23:19 AM
class Solution {
public:
    long long gcdll(int a, int b){
        if(a == 0 || b == 0){
            return a^b;
        }
        
        if(a<b){
            swap(a, b);
        }
        return gcdll(b, a%b);
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<long long> st;
        long long n = nums.size();
        for(long long i=0; i<n; i++){
            int cur = nums[i];
            while(!st.empty() && gcdll(st.top(), cur)>1){
                long long a = st.top(); st.pop();
                long long b = cur;
                long long gcd = gcdll(a, b);
                long long lc = (a*b)/(gcd);
                cur = lc;
            }
            st.push(cur);
        }
        vector<int> ans;
        while(!st.empty()){
            long long a = st.top(); st.pop();
            ans.push_back(a);
        }

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};