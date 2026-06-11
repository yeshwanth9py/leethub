# Last updated: 6/11/2026, 11:36:28 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        def dfs(root, curr_sum):
            if (root==None):
                return False

            curr_sum += root.val

            if(root.left is None and root.right is None):
                return curr_sum == targetSum
            
            return dfs(root.left, curr_sum) or dfs(root.right, curr_sum)
        return dfs(root, 0)