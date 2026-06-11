# Last updated: 6/11/2026, 11:35:21 AM
class Solution:
    def reverseBits(self, n: int) -> int:
        multiplier = 2**31
        tot_sum = 0
        while(n):
            last_digit = n&1
            tot_sum += multiplier*last_digit
            n = n >> 1
            multiplier = multiplier//2
            print(tot_sum)
        return tot_sum