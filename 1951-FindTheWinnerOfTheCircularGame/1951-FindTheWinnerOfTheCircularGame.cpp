// Last updated: 6/11/2026, 11:25:46 AM
class Solution {
public:
    int rec(int n, int k){
        if(n==1){
            return 0;
        }
        return (rec(n-1, k)+k)%n;
    }

    int findTheWinner(int n, int k) {
        // cout<<rec(3, 2)+1<<endl;
        return rec(n, k)+1;
    }
};