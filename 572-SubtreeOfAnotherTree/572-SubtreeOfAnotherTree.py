# Last updated: 6/11/2026, 11:32:23 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if(root is None):
            return
        if(root.val == subRoot.val):
            if(self.check_same(root,subRoot)):
                return True
        return (self.isSubtree(root.left, subRoot) or self.isSubtree(root.right,subRoot) or False)
        
    def check_same(self, p, q):
        if(p is None and q is None):
            return True
        if(p is None or q is None):
            return False
        if(p.val != q.val):
            return False
        return (self.check_same(p.left, q.left) and self.check_same(p.right, q.right))
        