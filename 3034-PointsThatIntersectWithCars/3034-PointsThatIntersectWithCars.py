# Last updated: 6/11/2026, 11:20:22 AM
class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        maxp = 0
        ct = 0
        for i in nums:
            maxp = max(maxp, i[1])
        points = [-1]*maxp
        for i in nums:
            for j in range(i[0],i[1]+1):
                
                if(points[j-1]!=1):
                    points[j-1] = 1
                    ct += 1
        return ct
                