# Last updated: 6/11/2026, 11:33:46 AM
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        count_dict = {}
        for i in nums:
            if i in count_dict:
                count_dict[i] += 1
            else:
                count_dict[i] = 1
        
        freq_array = [[] for _ in range(len(nums)+1)]

        for i in count_dict:
            freq_array[count_dict[i]].append(i)
            
        ans = []
        
        ct = 0
        print(freq_array)
        for i in range(len(freq_array)-1,-1,-1):
            for el in freq_array[i]:
                ans.append(el)
                ct+= 1
                if(ct == k):
                    return ans
        return []