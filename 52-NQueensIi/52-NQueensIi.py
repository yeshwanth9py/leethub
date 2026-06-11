# Last updated: 6/11/2026, 11:37:37 AM
class Solution:
    def totalNQueens(self, n: int) -> int:
        totalq = [0]
        queens = [[0]*n for _ in range(n)]

        def canplacequeen(r, c):
            tempr = r
            tempc = c
            for i in range(tempr):
                if(queens[i][c] == 1):
                    return False

            for j in range(c):
                if(queens[r][j]==1):
                    return False
            
            while(tempr>=0 and tempc>=0):
                if(queens[tempr][tempc] == 1):
                    return False
                tempr-=1
                tempc -=1
            
            tempr = r
            tempc = c

            while(tempr>=0 and tempc<n):
                if(queens[tempr][tempc] == 1):
                    return False
                tempc+=1
                tempr -= 1
            return True

        def placequeen(ind):
            if(ind == n):
                print("queens")
                totalq[0] += 1
                return totalq[0]
            
            for c in range(0, n):
                if(canplacequeen(ind, c)):
                    queens[ind][c] = 1
                    placequeen(ind+1)
                    queens[ind][c] = 0
                    
            
            return totalq[0]

        return placequeen(0)


                        