// Last updated: 6/11/2026, 11:31:51 AM
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev_count = 0;   // Length of the previous block of identical characters
        int curr_count = 1;   // Length of the current block
        int total_substrings = 0;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                // Same character as before, extend the current block
                curr_count++;
            } else {
                // Character changed, add valid substrings formed by prev and curr blocks
                total_substrings += min(prev_count, curr_count);
                // The current block now becomes the previous block
                prev_count = curr_count;
                // Reset current block length to 1 for the new character
                curr_count = 1;
            }
        }
        
        // Don't forget to add the valid substrings from the last two blocks
        total_substrings += min(prev_count, curr_count);
        
        return total_substrings;
    }
};