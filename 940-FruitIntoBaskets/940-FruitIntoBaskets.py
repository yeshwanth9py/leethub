# Last updated: 6/11/2026, 11:30:29 AM
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        d = {}
        l = 0
        res = 0
        for r in range(len(fruits)):
            if(fruits[r] in d):
                d[fruits[r]] += 1
            else:
                d[fruits[r]] = 1
            
            while(len(d)>2):
                d[fruits[l]] -= 1

                if(d[fruits[l]] == 0):
                    del d[fruits[l]]
                l += 1
            
            res = max(res, r-l+1)
        
        return res
            

            