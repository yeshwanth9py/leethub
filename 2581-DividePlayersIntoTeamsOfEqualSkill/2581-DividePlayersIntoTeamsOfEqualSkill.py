# Last updated: 6/11/2026, 11:21:50 AM
class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        totsum = sum(skill)
        n = len(skill)

        ps = totsum/(n/2)

        map = {}
        p = 0
        ans = 0
        for i in skill:
            if (ps-i) in map:
                map[ps-i] -= 1
                p += 1
                ans += (i*(ps-i))
                if(map[ps-i] == 0):
                    del map[ps-i]
            else:
                if i in map:
                    map[i] += 1
                else:
                    map[i] = 1
        
        if(p == n/2):
            return int(ans)
        else:
            return -1