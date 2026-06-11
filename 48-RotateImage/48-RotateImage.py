# Last updated: 6/11/2026, 11:37:54 AM
class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if(i!=j and i<=j):
                    matrix[i][j],matrix[j][i] = matrix[j][i],matrix[i][j]

        print(matrix)
        for j in range(len(matrix[0])//2):
            for i in range(len(matrix)):
                matrix[i][j],matrix[i][len(matrix[0])-j-1] = matrix[i][len(matrix[0])-j-1],matrix[i][j]

        