# Last updated: 6/11/2026, 11:25:26 AM
class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while(part in s):
            print(s)
            s = s.replace(part, "", 1)
            print(s)
        return s



        
        