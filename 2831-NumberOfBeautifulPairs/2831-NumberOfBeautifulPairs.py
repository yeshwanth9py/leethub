# Last updated: 6/11/2026, 11:20:48 AM
class Solution:
    def countBeautifulPairs(self, nums: List[int]) -> int:
        def gcd(a,b):
            min_val = min(a,b)
            for j in range(min_val,0,-1):
                if(a%j == 0 and b%j == 0):
                    return j
        ct = 0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                digit_1 = int(str(nums[i])[0])
                digit_2 = nums[j]%10
                print(digit_1, digit_2, gcd(digit_1,digit_2))
                if(gcd(digit_1,digit_2) == 1):
                    ct += 1
        return ct