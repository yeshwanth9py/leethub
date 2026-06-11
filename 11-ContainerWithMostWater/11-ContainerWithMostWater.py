# Last updated: 6/11/2026, 11:38:44 AM
class Solution:
    def maxArea(self, height: List[int]) -> int:
        l = 0
        r = len(height)-1

        maxar = 0
        while(l<r):
            maxar = max(maxar, (r-l)*(min(height[l],height[r])))
            if(height[l]<height[r]):
                l += 1
            else:
                r -= 1
        return maxar

        