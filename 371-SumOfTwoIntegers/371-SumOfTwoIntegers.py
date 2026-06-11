# Last updated: 6/11/2026, 11:33:33 AM
class Solution:
    def getSum(self, a: int, b: int) -> int:
        # mask = 0b11111111111111111111111111111111
        mask = 0xffffffff
        while((mask&b)!=0):
            sum = a ^ b
            carry = a & b
            a = sum
            b = carry << 1
        return (mask&a) if b>0 else a




