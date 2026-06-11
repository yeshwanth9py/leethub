# Last updated: 6/11/2026, 11:37:51 AM
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        big_dict = defaultdict(list)
        for i in strs:
            arr = [0]*26
            freqdict = Counter(i)
            for el in freqdict:
                arr[ord("a")-ord(el)] = freqdict[el]

            big_dict[tuple(arr)].append(i)

        return big_dict.values()


        