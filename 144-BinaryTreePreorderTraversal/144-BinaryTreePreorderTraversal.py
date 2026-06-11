# Last updated: 6/11/2026, 11:35:53 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if(root is None):
            return []
        ans= []
        stack = []
        stack.append(root)
        while(len(stack)>0):
            cur = stack.pop()
            if(cur is None):
                continue
            ans.append(cur.val)
            if(cur.right):
                stack.append(cur.right)
            if(cur.left):
                stack.append(cur.left)
        return ans
            
            

