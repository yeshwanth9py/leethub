# Last updated: 6/11/2026, 11:32:11 AM
class Solution:
    def countSubstrings(self, s: str) -> int:
        ct = 0
        for c in range(len(s)):
            i=c
            j=c
            while(i>=0 and j<len(s) and s[i]==s[j]):
                ct +=1
                i=i-1
                j=j+1

            i = c
            j = c+1
            while(i>=0 and j<len(s) and s[i]==s[j]):
                ct += 1
                i = i-1
                j = j+1
        return ct
