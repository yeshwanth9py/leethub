# Last updated: 6/11/2026, 11:34:21 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        def fun(root):
            if(root is None or root == p or root == q):
                return root
            left = fun(root.left)
            right = fun(root.right)
            if(left is None):
                return right
            elif(right is None):
                return left
            else:
                return root
        return fun(root)