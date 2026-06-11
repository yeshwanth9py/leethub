# Last updated: 6/11/2026, 11:36:20 AM
class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
       
        s2 = ""
        for st in s:
            if(st!=" " and st.isalnum()):
                s2 += st.lower()

        j = len(s2)-1
        while(i<=j):
            if(s2[i]==s2[j]):
                i = i+1
                j -=1
            else:
                return False
        return True
            
            
        