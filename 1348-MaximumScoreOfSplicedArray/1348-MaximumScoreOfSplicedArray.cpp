// Last updated: 6/11/2026, 11:28:47 AM
class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        long long n = nums1.size();
        vector<long long> psum1(n, 0), psum2(n, 0);

        psum1[0] = nums1[0];
        psum2[0] = nums2[0];

        for(long long i=1; i<n; i++){
            psum1[i] = psum1[i-1]+nums1[i];
            psum2[i] = psum2[i-1]+nums2[i];
        }
        
        long long ans = max(psum1[n-1], psum2[n-1]);

        long long smalld1 = 0;
        long long smalld2 = 0;
        long long ind1 = -1;
        long long ind2 = -1;

        for(long long i=0; i<n; i++){
            long long val1 = psum1[i]-psum2[i];
            long long val2 = psum2[i]-psum1[i];
            // //replace single elem seperately
            // ans = max(ans, psum1[n-1]-nums1[i]+nums2[i]);
            // ans = max(ans, psum2[n-1]-nums2[i]+nums1[i]);

            if(val1>smalld1){
                //ind+1 to i  
                long long ar1sum = psum1[n-1] - (psum1[i]-(ind1>=0?psum1[ind1]:0)) + (psum2[i]-(ind1>=0?psum2[ind1]:0));
                long long ar2sum = psum2[n-1] - (psum2[i]-(ind1>=0?psum2[ind1]:0)) + (psum1[i]-(ind1>=0?psum1[ind1]:0));
                ans = max(ans, ar1sum);
                ans = max(ans, ar2sum);
            }

            if(val2>smalld2){
                long long ar1sum = psum1[n-1] - (psum1[i]-(ind2>=0?psum1[ind2]:0)) + (psum2[i]-(ind2>=0?psum2[ind2]:0));
                long long ar2sum = psum2[n-1] - (psum2[i]-(ind2>=0?psum2[ind2]:0)) + (psum1[i]-(ind2>=0?psum1[ind2]:0));
                ans = max(ans, ar1sum);
                ans = max(ans, ar2sum);
            }

            if(smalld1>val1){
                smalld1 = val1;
                ind1 = i;
            }

            if(smalld2>val2){
                smalld2 = val2;
                ind2 = i;
            }
        }

        return ans;


    }
};