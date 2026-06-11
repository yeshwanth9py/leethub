// Last updated: 6/11/2026, 11:16:35 AM
class Solution {
public:
    long long nc2(long long n){
        if(n<=1) return 0; 
        return (n*(n-1))/2;
    }

    long long minMaxSubarraySum(vector<int>& arr, long long k) {
        long long n = arr.size();
        stack<long long> st;
        vector<long long> prevmin(n, -1);

        for(long long i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prevmin[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

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

        while(!st.empty()) st.pop();

        vector<long long> prevmax(n, -1);
        for(long long i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prevmax[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<long long> nextmax(n, n);
        for(long long i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nextmax[i] = st.top();
            }
            st.push(i);
        }

        long long ans = 0;
        for(long long i=0; i<n; i++){
            long long pi = prevmin[i];
            long long ni = nextmin[i];
            pi++;
            ni--;
            if(i-pi+1>k){
                // k = i-pi+1;
                pi = i-k+1; 
            }

            if(ni-i+1>k){
                //k = ni-i+1
                ni = k+i-1;
            }

            long long left = i-pi+1;
            long long right = ni-i+1;

            long long contrib = nc2(k+1) - nc2(k+1-left) - nc2(k+1-right) + nc2(k+1-left-right);
            ans += contrib*arr[i];


            pi = prevmax[i];
            ni = nextmax[i];
            pi++;
            ni--;

            left = i-pi+1;
            right = ni-i+1;
            left = min(left, k);
            right = min(right, k);

            contrib = nc2(k+1) - nc2(k+1-left) - nc2(k+1-right) + nc2(k+1-left-right);
            ans += contrib*arr[i];
        }

        return ans;

    }
};