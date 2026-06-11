# Last updated: 6/11/2026, 11:37:33 AM
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        bottom = len(matrix)
        top = 0
        right = len(matrix[0])
        left = 0
        op = []
        while(left < right and top < bottom):
            for i in range(left,right):
                op.append(matrix[top][i])

            top = top+1

            for i in range(top,bottom):
                op.append(matrix[i][right-1])

            right = right-1
            
            if (not(left<right) or not(top<bottom)):
                return op

            for i in range(right-1,left-1,-1):
                op.append(matrix[bottom-1][i])
            
            bottom -=1 
        
            for i in range(bottom-1,top-1,-1):
                op.append(matrix[i][left])

            left += 1

        return op