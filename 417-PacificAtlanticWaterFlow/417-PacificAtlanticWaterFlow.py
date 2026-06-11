# Last updated: 6/11/2026, 11:33:19 AM
class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        rows = len(heights)-1
        cols = len(heights[0])-1

        pac,atl = set(),set()


        def dfs(r,c,prevheight,vis):
            if (r,c) in vis:
                return
            if(r<0 or c<0 or r>rows or c>cols or prevheight>heights[r][c]):
                return 
            vis.add((r,c))

            dfs(r+1,c,heights[r][c],vis)
            dfs(r-1,c,heights[r][c],vis)
            dfs(r,c+1,heights[r][c],vis)
            dfs(r,c-1,heights[r][c],vis)
            
        

        for c in range(cols+1):
            dfs(0,c,heights[0][c],pac)
            dfs(rows,c,heights[rows][c],atl)
        
        for r in range(rows+1):
            dfs(r,cols,heights[r][cols],atl)
            dfs(r,0,heights[r][0],pac)
        
        return list(pac & atl)

        return []
