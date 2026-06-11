# Last updated: 6/11/2026, 11:34:18 AM
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        
        arr1 = sorted(s)
        dict1 = {}
        for i in arr1:
            dict1[i] = dict1.get(i,0)+1
        
        arr2 = sorted(t)
        dict2 = {}
        for i in arr2:
            dict2[i] = dict2.get(i,0)+1

        return dict1 == dict2
