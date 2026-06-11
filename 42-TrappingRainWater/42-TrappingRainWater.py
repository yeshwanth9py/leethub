# Last updated: 6/11/2026, 11:38:01 AM
class Solution:
    def trap(self, height: List[int]) -> int:
        twt = 0

        lm = [0]*(len(height))
        rm = [0]*(len(height))

        lm[0] = 0
        for i in range(1,len(height)):
            lm[i] = max(lm[i-1], height[i-1])

        rm[len(height) -1] = 0
        for i in range(len(height)-2, -1, -1):
            rm[i] = max(rm[i+1], height[i+1])


        for i in range(1,len(height)-1):
            curh = height[i]
            # lefth = 0
            # for j in range(0, i):
            #     lefth = max(lefth, height[j])
            # righth = 0
            # for j in range(len(height)-1, i, -1):
            #     righth = max(righth, height[j])

            wt = (min(lm[i], rm[i]) - curh)
            if(wt>0):
                twt += wt
        return twt