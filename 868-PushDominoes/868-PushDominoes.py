# Last updated: 6/11/2026, 11:30:54 AM
class Solution:
    def pushDominoes(self, dominoes: str) -> str:
        n = len(dominoes)
        force = [0]*n

        # left to right
        f = 0
        for i in range(len(dominoes)):
            if(dominoes[i] == "L"):
                f = 0
            elif(dominoes[i] == "R"):
                f = n
            else:
                f = max(f-1, 0)
            force[i] = f
        
        # right to left
        f = 0
        for i in range(n-1, -1, -1):
            if(dominoes[i] == "R"):
                f = 0
            elif(dominoes[i] == "L"):
                f = n
            else:
                f = max(f-1, 0)
            force[i] -= f
        
        print(force)
        ans = ""
        for i in force:
            if i>=1:
                ans+="R"
            elif i<=-1:
                ans += "L"
            else:
                ans += "."
        return ans