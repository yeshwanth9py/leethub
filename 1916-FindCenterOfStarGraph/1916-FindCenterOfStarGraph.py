# Last updated: 6/11/2026, 11:25:58 AM
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        a = edges[0]
        b = edges[1]

        for i in a:
            if i in b:
                return i