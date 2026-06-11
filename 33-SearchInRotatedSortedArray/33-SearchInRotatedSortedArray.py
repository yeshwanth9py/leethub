# Last updated: 6/11/2026, 11:38:18 AM
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low = 0
        high = len(nums)-1
        while(low<=high):
            mid = (low+high)//2
            # check if left is sorted
            if(nums[mid] == target):
                return mid
            elif(nums[low]==target):
                return low
            elif(nums[high]==target):
                return high
            elif(nums[0]<nums[mid]):
                if(target<=nums[mid] and target>=nums[0]):
                    high = mid-1
                else:
                    low = mid+1
            else:
                if(target<=nums[high] and target>=nums[mid]):
                    low = mid+1
                else:
                    high = mid-1
        return -1
                

        
        