# Last updated: 6/11/2026, 11:36:36 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:

        def dfs(root):
            if(root is None):
                return 0

            lh = dfs(root.left)
            rh = dfs(root.right)
            return 1+max(lh, rh)
        if(root is None):
            return True
            
        lh = dfs(root.left)      
        rh = dfs(root.right)      
        if(abs(lh-rh)>1):
            return False
        else:
            return self.isBalanced(root.left) and self.isBalanced(root.right)
            
        