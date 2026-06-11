# Last updated: 6/11/2026, 11:28:49 AM
class Solution:
    def getMaximumGold(self, grid: List[List[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])

        vis= [[0]*(cols+1) for _ in range(rows+1)]
        
        def rec(r, c):
            if(r<0 or c<0 or r>=rows or c>=cols or grid[r][c] == 0):
                return 0
            if(vis[r][c] == 1):
                return 0
            gold = grid[r][c]
            # grid[r][c] = 0
            vis[r][c] = 1

            top = rec(r+1, c)
            bottom = rec(r-1, c)
            right = rec(r, c+1)
            left = rec(r, c-1)

            vis[r][c] = 0
            # grid[r][c] = gold
            return gold+max(top, left, right, bottom)
        
        maxg = 0
        for i in range(rows):
            for j in range(cols):
                if(grid[i][j]!=0):
                    # vis = [[0]*(cols+1) for _ in range(rows+1)]
                    maxg = max(maxg, rec(i, j))
        return maxg
        

