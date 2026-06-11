// Last updated: 6/11/2026, 11:24:10 AM
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int max_dist = 0;
        
        // Scenario 1: Fix the first house, look from the right
        for (int i = n - 1; i >= 0; --i) {
            if (colors[i] != colors[0]) {
                max_dist = max(max_dist, i); // i - 0 is just i
                break;
            }
        }
        
        // Scenario 2: Fix the last house, look from the left
        for (int i = 0; i < n; ++i) {
            if (colors[i] != colors[n - 1]) {
                max_dist = max(max_dist, n - 1 - i);
                break;
            }
        }
        
        return max_dist;
    }
};