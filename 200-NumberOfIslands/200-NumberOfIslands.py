# Last updated: 6/11/2026, 11:35:08 AM
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        visited = set()
        count_islands = 0
        def dfs(r,c,visited):
            if(r<0 or c<0 or r>=len(grid) or c>=len(grid[0]) or (r,c) in visited):
                return
            visited.add((r,c))
            if(grid[r][c] == "1"):
                directions = [[0,1],[1,0],[0,-1],[-1,0]]
                for dr, dc in directions:
                    nr = r+dr
                    nc = c+dc
                    dfs(nr,nc,visited)


            
        for r in range(len(grid)):
            for c in range(len(grid[0])):
                if(grid[r][c] == "1" and (r,c) not in visited):
                    dfs(r,c,visited)
                    count_islands += 1
        return count_islands
