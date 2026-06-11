// Last updated: 6/11/2026, 11:15:30 AM
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int totalCells = n * n;
        int maxByWeight = maxWeight / w;
        return min(totalCells, maxByWeight);
        
    }
};