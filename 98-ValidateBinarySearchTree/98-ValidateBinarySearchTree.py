# Last updated: 6/11/2026, 11:36:53 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # def isValidBST(self, root: Optional[TreeNode]) -> bool:
    #     self.isBSTHelper(root,float('-inf'), float('inf'))
    # def isBSTHelper(self, node, lower, high):
    #     if not node:
    #         return True

    #     if not (lower<node.val and node.val<high):
    #         return False

    #     return self.isBSTHelper(node.left, lower, node.val) and self.isBSTHelper(node.right, node.val, high)

    def isValidBST(self, root: TreeNode) -> bool:
        def valid(node, left, right):
            if not node:
                return True
            if not(left<node.val<right):
                return False
            # if(left > node.val or node.val<right):
            #     return False

            return valid(node.left, left, node.val) and valid(
                node.right, node.val, right
            )

        return valid(root, float("-inf"), float("inf"))