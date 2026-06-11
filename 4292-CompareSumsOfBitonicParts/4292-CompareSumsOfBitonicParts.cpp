// Last updated: 6/11/2026, 11:09:17 AM
class Solution {
public:
    int compareBitonicSums(vector<int>& arr) {
        long long asc = 0;
        long long i = 1;
        long long n = arr.size();

        long long prevs = arr[0];
        while(i<n && arr[i]>arr[i-1]){
            prevs += arr[i];
            i++;
        }
        
        long long incrs = arr[i-1];
        while(i<n && arr[i]<arr[i-1]){
            incrs += arr[i];
            i++;
        }
        
        // cout<<incrs<<" "<<prevs;
        if(incrs == prevs) return -1;
        if(prevs>incrs) return 0;
        return 1;
        
    }
};