# Last updated: 6/11/2026, 11:38:50 AM
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        hash_set = set()
        i = 0
        j = 0
        maxlen = 0
        while(j<len(s)):
            while(s[j] in hash_set):
                hash_set.remove(s[i])
                i += 1
            maxlen = max(maxlen, j-i+1)
            hash_set.add(s[j])
            j +=1
            
        return maxlen

