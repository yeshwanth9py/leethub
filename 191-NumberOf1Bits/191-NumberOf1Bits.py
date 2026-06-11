# Last updated: 6/11/2026, 11:35:14 AM
class Solution:
    def hammingWeight(self, n: int) -> int:      
        # res = 0
        # while(n):
        #     res += n%2
        #     n = n>>1
        # return res

        res = 0
        while(n):
            n = n & n-1
            res = res + 1
        return res
        
        
