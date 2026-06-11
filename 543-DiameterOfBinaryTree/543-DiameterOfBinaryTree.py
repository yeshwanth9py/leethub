# Last updated: 6/11/2026, 11:32:43 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # appr-1
    # def height(self, root):
    #     if root is None:
    #         return 0
    #     return 1+ max(self.height(root.left), self.height(root.right))
    
    # def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
    #     if(root is None):
    #         return 0
    #     lh = self.diameterOfBinaryTree(root.left)
    #     rh = self.diameterOfBinaryTree(root.right)
    #     ch = self.height(root.left)+self.height(root.right)
    #     return max(lh, rh, ch)

    #appr-2
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        ans = [0]
        def diam(root, ans):
            if root is None:
                return 0
            lh = diam(root.left, ans)
            rh= diam(root.right, ans)
            ans[0] = max(ans[0], lh+rh)
            return 1+max(lh, rh)
        diam(root, ans)
        return ans[0]

