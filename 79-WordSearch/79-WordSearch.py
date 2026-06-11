# Last updated: 6/11/2026, 11:37:09 AM
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])

        vis = [[0]*n for _ in range(m)]


        def isinboard(row, col):
            if(row<0 or col<0 or row>=m or col>=n):
                return False
            return True

        flag = [False]

        def rec(ind, r, c):

            if(ind==len(word)):
                flag[0] = True
                return True
            # top = rec(ind+1, r-1, c)
            
            
            # print(board[r][c], ind)
            top = False
            bottom = False
            left = False
            right = False

            newr = r
            newc = c-1

            if(isinboard(newr, newc) and vis[newr][newc]==0 and board[newr][newc]==word[ind]):
                vis[newr][newc] = 1
                top = rec(ind+1, newr, newc)
                vis[newr][newc] = 0

            newr= r
            newc = c+1
            if(isinboard(newr, newc) and vis[newr][newc]==0 and board[newr][newc]==word[ind]):
                vis[newr][newc] = 1
                bottom = rec(ind+1, newr, newc)
                vis[newr][newc] = 0


            newr = r-1
            newc = c

            if(isinboard(newr, newc) and vis[newr][newc]==0 and board[newr][newc]==word[ind]):
                vis[newr][newc] = 1
                left = rec(ind+1, newr, newc)
                vis[newr][newc] = 0

            newr = r+1
            newc = c
            if(isinboard(newr, newc) and vis[newr][newc]==0 and board[newr][newc]==word[ind]):
                vis[newr][newc] = 1
                right = rec(ind+1, newr, newc)
                vis[newr][newc] = 0

            return top or bottom or left or right


            
            

        for i in range(m):
            for j in range(n):
                if(word[0] == board[i][j]):
                    vis[i][j] = 1
                    rec(1, i, j)
                    vis[i][j] = 0
                    if(flag[0]):
                        return True
        return False