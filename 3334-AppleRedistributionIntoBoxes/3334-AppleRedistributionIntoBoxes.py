# Last updated: 6/11/2026, 11:18:52 AM
class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        capacity.sort()
        sum1 =0;
        sum2 = sum(apple)
        curr = capacity[-1];
        sum1 += curr
        ct = 1
        while(sum1<sum2):
            capacity.remove(curr)
            curr = capacity[-1];
            sum1 += curr
            ct+=1
        return ct