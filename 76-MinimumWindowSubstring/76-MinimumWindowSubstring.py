# Last updated: 6/11/2026, 11:37:08 AM
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        have = 0
        

        stored = ""
        
        given = {}
        for i in t:
            given[i] = given.get(i, 0) + 1
        want = len(given)
        window = {}
        
        i = 0
        j = 0
        minlen = 100000

        while(j<len(s)):
            if(s[j] in given):
                window[s[j]] = window.get(s[j], 0) + 1
                if(window[s[j]] == given[s[j]]):
                    have += 1
            while(have == want):
                if(j-i+1<minlen):
                    minlen = j-i+1
                    stored = s[i:j+1]
                
                if(s[i] in window):
                    window[s[i]] -= 1
                    if(window[s[i]] < given[s[i]]):
                        have -= 1
                i += 1           

            j += 1
        
        return stored