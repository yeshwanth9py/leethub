# Last updated: 6/11/2026, 11:36:34 AM
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        fans = []
        
        def fun(r):
            rowans= []
            ans = 1
            rowans.append(ans)
            for i in range(1,r):
                ans = ans*(r-i)
                ans = ans//(i)
                rowans.append(ans)
            k = rowans.copy()
            fans.append(k)

        for i in range(1,numRows+1):
            fun(i)
        return fans