// Last updated: 6/11/2026, 11:11:10 AM
class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        set<int> st;

        int cmx = 0;
        for(int i=n-1; i>=0; i--){
            st.insert(nums[i]);
            if(nums[i] == cmx){
                while(st.find(cmx)!= st.end()){
                    cmx++;
                }
            }
            arr[i] = cmx;
        }

        int i=0;
        vector<int> ans;
        
        while(i<n){
            int fm = arr[i];
            int j = i;
            int cmx = 0;
            set<int> st2;
            st2.insert(nums[j]);
            if(nums[j] == 0) cmx++;
            while(cmx<fm){
                j++;
                if(j>=n) break;
                st2.insert(nums[j]);
                if(nums[j] == cmx){
                    while(st2.find(cmx) != st2.end()){
                        cmx++;
                    }
                }
            }
            ans.push_back(cmx);
            i = j+1;
        }

        return ans;
    }
};