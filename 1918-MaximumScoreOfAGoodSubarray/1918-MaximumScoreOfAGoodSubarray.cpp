// Last updated: 6/11/2026, 11:25:49 AM
class Solution {
public:
    int maximumScore(vector<int>& arr, int k) {
        int n = arr.size();
        stack<int> st;

        vector<int> prevmin(n, -1);
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
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

        vector<int> nextmin(n, n);
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nextmin[i] = st.top();
            }
            st.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            // if(i == k){
            //     ans = max(ans, arr[i]);
            // }
            if(i<=k){
                int len = i-prevmin[i];
                if(nextmin[i]>k){
                    len += (nextmin[i]-i-1);
                    ans = max(ans, len*(arr[i]));
                }
            }else if(i>=k){
                int len = nextmin[i]-i;
                if(prevmin[i]<k){
                    len += (i-prevmin[i]-1);
                    ans = max(ans, len*(arr[i]));
                }
            }
        }

        return ans;

    }
};