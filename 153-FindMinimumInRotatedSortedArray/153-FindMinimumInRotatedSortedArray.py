# Last updated: 6/11/2026, 11:35:38 AM
class Solution:
    def findMin(self, nums: List[int]) -> int:
        low=0
        high = len(nums)-1
        mid = (low+high)//2

        ans = 10000
        while(low<=high):
            mid = (low+high)//2
            ans = min(ans, nums[mid], nums[low], nums[high])

            if(nums[0]<nums[mid]):
                # ans = min(ans,nums[low]s,);           
                low = mid+1
                
            else:
                # ans =  min(ans, nums[high])
                high= mid-1
                

        return ans
        
