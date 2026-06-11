# Last updated: 6/11/2026, 11:20:14 AM
from collections import Counter
import heapq
class Solution:
    def minLengthAfterRemovals(self, nums: List[int]) -> int:
        a = dict(Counter(nums))
        n = len(nums)
        a = a.values()
        maxf = max(a)
        if(maxf<=n/2):
            if(n%2 == 1):
                return 1
            return 0
        return maxf-(n-maxf)
    
                    
                    

                    
        
            
        
        
                
            