// Last updated: 6/11/2026, 11:21:44 AM
class Solution {
public:
    int closestTarget(vector<string>& arr, string tar, int si) {
        int n = arr.size();
        int l = ((si-1)+n)%n;
        int r = (si+1)%n;
        if(arr[si] == tar) return 0;
        int noc = 1;
        int dist = 1;
        while(noc<n){
            if(arr[l] == tar) return dist;
            if(arr[r] == tar) return dist;
            dist++;
            noc = noc+2;
            l = ((l-1)+n)%n;
            r = (r+1)%n;
        }

        return -1;
    }
};