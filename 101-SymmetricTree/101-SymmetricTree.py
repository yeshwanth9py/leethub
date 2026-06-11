# Last updated: 6/11/2026, 11:36:42 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if(root is None):
            return True

        def symmetric_help(left, right):
            if(left is None or right is None):
                return right == left
            if(left.val != right.val):
                return False
            return symmetric_help(left.left, right.right) and symmetric_help(left.right, right.left)
        return symmetric_help(root.left, root.right)