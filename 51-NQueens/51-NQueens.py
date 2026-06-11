# Last updated: 6/11/2026, 11:37:47 AM
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def is_safe(row, col, board):
            # Check for queens in the same column
            for i in range(row):
                if board[i][col] == 'Q':
                    return False
            
            # Check for queens in the upper left diagonal
            i, j = row - 1, col - 1
            while i >= 0 and j >= 0:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j -= 1
            
            # Check for queens in the upper right diagonal
            i, j = row - 1, col + 1
            while i >= 0 and j < n:
                if board[i][j] == 'Q':
                    return False
                i -= 1
                j += 1
            
            return True
        
        def backtrack(row, board, result):
            if row == n:
                result.append([''.join(row) for row in board])
                return
            
            for col in range(n):
                if is_safe(row, col, board):
                    board[row][col] = 'Q'
                    backtrack(row + 1, board, result)
                    board[row][col] = '.'
        
        board = [['.' for _ in range(n)] for _ in range(n)]
        result = []
        backtrack(0, board, result)
        return result
