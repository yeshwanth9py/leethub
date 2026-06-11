# Last updated: 6/11/2026, 11:24:32 AM
class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        set1 = set()
        set2 = set()
        set3 = set()

        ans = set()
        
        for i in nums1:
            set1.add(i)
        for j in nums2:
            if(j in set1):
                ans.add(j)
            else:
                set2.add(j)
        for k in nums3:
            if(k in set1 or k in set2):
                ans.add(k)
            else:
                set3.add(k)
        # print(ans)
        return list(ans)