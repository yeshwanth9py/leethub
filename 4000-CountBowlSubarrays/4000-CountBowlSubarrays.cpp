// Last updated: 6/11/2026, 11:14:03 AM
class Solution {
public:
    long long bowlSubarrays(vector<int>& arr) {
        long long n = arr.size();
        vector<long long> prevgrt(n, -1);
        vector<long long> nextgrt(n, n);
        stack<long long> st;
        st.push(n-1);
        for(long long i=n-2; i>=0; i--){
            while(!st.empty() && arr[i]>=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                nextgrt[i] = st.top();
            }else{
                nextgrt[i] = n;
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        st.push(0);
        for(long long i=1; i<n; i++){
            while(!st.empty() && arr[i]>=arr[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                prevgrt[i] = st.top();
            }else{
                prevgrt[i] = -1;
            }
            st.push(i);
        }

        long long ans = 0;
        for(long long i=0; i<n; i++){
            if(prevgrt[i]!=-1 && i-prevgrt[i]+1>=3){
                ans++;
            }
            if(nextgrt[i] != n && nextgrt[i]-i+1>=3){
                ans++;
            }
        }

        return ans;

        
        
    }
};