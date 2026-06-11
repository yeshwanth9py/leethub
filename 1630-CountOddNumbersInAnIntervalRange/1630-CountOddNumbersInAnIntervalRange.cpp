// Last updated: 6/11/2026, 11:27:16 AM
class Solution {
public:
    int countOdds(int low, int high) {
        int a = (high+1)/2;
        int b = (low)/2;
        cout<<a<<" "<<b<<endl;
        return a-b;
    }
};