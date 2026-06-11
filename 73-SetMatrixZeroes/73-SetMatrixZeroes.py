# Last updated: 6/11/2026, 11:37:20 AM
class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        rows = len(matrix)
        cols = len(matrix[0])

        col = [0]*(cols)
        row = [0]*(rows)
        for i in range(rows):
            for j in range(cols):
                if(matrix[i][j] == 0):
                    col[j] = 1
                    row[i] = 1

        for i in range(rows):
            for j in range(cols):
                if(row[i] == 1 or col[j] == 1):
                    matrix[i][j] = 0