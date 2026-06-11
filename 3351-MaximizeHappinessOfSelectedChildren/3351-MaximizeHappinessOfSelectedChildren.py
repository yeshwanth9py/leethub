# Last updated: 6/11/2026, 11:18:46 AM
class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort() 
        sum1 = 0
        delay = 0
        for i in range(k):
            curr = happiness[-(i+1)]
            # print(curr)
            sum1 += max(0,curr - delay)
            # print(sum1)
            delay+=1
        return sum1
            
        