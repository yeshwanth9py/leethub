# Last updated: 6/11/2026, 11:35:13 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        stack = []
        def fun(root, l):
            if root is None:
                return
            if(l == len(stack)):
                stack.append(root.val)
            fun(root.right, l+1)
            fun(root.left, l+1)
        fun(root, 0)
        print(stack)
        return stack
