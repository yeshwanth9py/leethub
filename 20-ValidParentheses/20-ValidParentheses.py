# Last updated: 6/11/2026, 11:38:31 AM
class Solution:
    def isValid(self, s: str) -> bool:
        store = {"{":"}","[":"]","(":")"}

        stack = []
        for i in range(len(s)):
            if (s[i] in store):
                stack.append(s[i])
            else:
                if(stack == []):
                    return False
                else:
                    if(store[stack.pop()] != s[i]):
                        return False
        if(stack != []):
            return False
        return True
