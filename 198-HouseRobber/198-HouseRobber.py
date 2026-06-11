# Last updated: 6/11/2026, 11:35:16 AM
class Solution:
    def rob(self, nums: List[int]) -> int:
        # max_money = [0]
        
        # def count_max(ind, money, dp):
        #     if(ind >= len(nums)):
        #         max_money[0] = max(max_money[0],money)                 
        #         return

        #     count_max(ind+1, money)

        #     count_max(ind+2, money+nums[ind])

        # count_max(0,0)
        # return max_money[0]

        rob1 = 0
        rob2 = 0
        for ind in range(len(nums)):
            temp = max((nums[ind]+rob1),rob2)
            rob1 = rob2
            rob2 = temp
        return temp
