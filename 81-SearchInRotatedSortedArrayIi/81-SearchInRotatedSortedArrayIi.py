# Last updated: 6/11/2026, 11:37:02 AM
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        low= 0
        high = len(nums)-1
        while(low<=high):
            while(low<high and nums[low] == nums[low+1]):
                low += 1
            while(low<high and nums[high] == nums[high-1]):
                high -= 1 
            mid= (low+high)//2
            print(mid)

            if(nums[mid] == target):
                return True
            elif(nums[low] == target):
                return True
            elif(nums[high]==target):
                return True
                      
            if(nums[0]<nums[mid]):
                if(target>=nums[0] and target<nums[mid]):
                    high = mid-1
                else:
                    low=mid+1
            else:
                if(target>nums[mid] and target<nums[high]):
                    low= mid+1
                else:
                    high = mid-1

        return False