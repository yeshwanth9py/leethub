// Last updated: 6/11/2026, 11:26:27 AM
class Solution {
public:
    int minPartitions(string n) {
        sort(n.rbegin(), n.rend());
        
        return (n[0]-'0');
    }
};