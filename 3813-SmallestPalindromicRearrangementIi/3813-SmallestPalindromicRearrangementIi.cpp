// Last updated: 6/11/2026, 11:15:32 AM
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Helper: Compute n choose k but "cap" the result to cap.
    // That is, if the computed value exceeds cap, return cap.
    unsigned long long nCkCapped(int n, int k, unsigned long long cap) {
        if (k > n) return 0;
        if (k > n - k) k = n - k;  // use symmetry
        unsigned long long res = 1;
        for (int i = 1; i <= k; i++) {
            // Multiply res by (n - i + 1) first, then divide by i.
            res = res * (n - i + 1) / i;
            if (res > cap) return cap;
        }
        return res;
    }
    
    // Helper: Compute multinomial coefficient for a multiset.
    // total: total number of items,
    // count: frequency array for letters,
    // cap: the maximum value (if result exceeds cap, we return cap).
    unsigned long long multinomialCapped(const vector<int>& count, int total, unsigned long long cap) {
        unsigned long long res = 1;
        int rem = total;
        for (int c : count) {
            if (c > 0) {
                unsigned long long ways = nCkCapped(rem, c, cap);
                // Multiply res and cap the result.
                if (res > cap / ways) return cap;
                res *= ways;
                rem -= c;
                if (res > cap) return cap;
            }
        }
        return res;
    }
    
    // Given the multiset described by leftCount with total size "total",
    // compute the kth lexicographical permutation.
    // All computations compare values with k, so we only care if counts exceed k.
    string kthPermutationForMultiset(const vector<int>& initCount, int total, unsigned long long k) {
        vector<int> count = initCount;  // copy the frequency count
        string result;
        for (int pos = 0; pos < total; pos++) {
            // Try each candidate letter in lexicographical order.
            for (int letter = 0; letter < 26; letter++) {
                if (count[letter] == 0) continue;
                count[letter]--; // choose this letter tentatively
                // Compute number of distinct arrangements for the remaining positions.
                unsigned long long ways = multinomialCapped(count, total - pos - 1, k);
                if (k > ways) {
                    // kth permutation is not in this block; skip it.
                    k -= ways;
                    count[letter]++; // restore the count
                } else {
                    // This letter is fixed at the current position.
                    result.push_back('a' + letter);
                    break;
                }
            }
        }
        return result;
    }
    
    // Main function: Given a palindromic string s and integer k,
    // return the kth lexicographically smallest palindromic permutation.
    // If there are fewer than k distinct palindromic permutations, return an empty string.
    // The left half is stored in the variable prelunthak.
    string smallestPalindrome(string s, unsigned long long k) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        string prelunthak; // left half
        string mid;       // middle character (if any)
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                // More than one odd frequency would yield no valid palindrome.
                if (!mid.empty()) return "";
                mid = string(1, 'a' + i);
            }
            prelunthak.append(freq[i] / 2, 'a' + i);
        }
        
        // Compute the frequency of letters in prelunthak.
        vector<int> leftCount(26, 0);
        for (char c : prelunthak)
            leftCount[c - 'a']++;
        int leftSize = prelunthak.size();
        
        // Compute total number of distinct permutations for the left half,
        // but cap the result at k so we don't overflow.
        unsigned long long totalPerm = multinomialCapped(leftCount, leftSize, k);
        if (k < 1 || k > totalPerm)
            return "";
        
        // Get kth permutation for the left half.
        string leftPermutation = kthPermutationForMultiset(leftCount, leftSize, k);
        string rightPermutation = leftPermutation;
        reverse(rightPermutation.begin(), rightPermutation.end());
        return leftPermutation + mid + rightPermutation;
    }
};
