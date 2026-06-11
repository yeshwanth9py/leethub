# Last updated: 6/11/2026, 11:32:18 AM
class Solution:
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs = sorted(pairs, key = lambda x: x[1])
        cnt = 0
        prevtail = -10000
        for head, tail in pairs:
            if(head>prevtail):
                prevtail = tail
                cnt+=1
        return cnt