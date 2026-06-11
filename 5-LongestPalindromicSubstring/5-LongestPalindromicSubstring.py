# Last updated: 6/11/2026, 11:38:53 AM
class Solution:
    def longestPalindrome(self, s: str) -> str:
        maxlen = 0
        word = ""
        for c in range(len(s)):
            i = j = c
            while(i>=0 and j<len(s) and s[i]==s[j]):
                if(maxlen<j-i+1):
                    maxlen = j-i+1
                    word = s[i:j+1]
                i=i-1
                j=j+1
            
            i = c
            j = c+1
            while(i>=0 and j<len(s) and s[i]==s[j]):
                if(maxlen<j-i+1):
                    maxlen= j-i+1
                    word=s[i:j+1]
                i=i-1
                j=j+1
            
        return word
            
