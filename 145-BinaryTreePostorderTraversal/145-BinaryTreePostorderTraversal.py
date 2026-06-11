# Last updated: 6/11/2026, 11:35:49 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack1 = []
        stack2 = []
        stack1.append(root)
        while(len(stack1)!=0):
            cur = stack1.pop()
            if(cur is None):
                break
            stack2.append(cur.val)
            if(cur.left is not None):
                stack1.append(cur.left)
            if(cur.right is not None):
                stack1.append(cur.right)
        stack2.reverse()
        return stack2
