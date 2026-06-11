# Last updated: 6/11/2026, 11:34:35 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        # if i do left,root,right(inorder traversal) in bst we get all the nodes automatically in sorted manner ---o(k)
        # def helper_inorder(root, arr):
        #     if(root is None):
        #         return False
        #     if (len(arr) == k):
        #         return arr[-1]
        #     if(root.left and (n := helper_inorder(root.left, arr))):
        #         return n
        #     arr.append(root.val)
        #     if(root.right and (n := helper_inorder(root.right, arr))):
        #         return n
        #     if (len(arr) == k):
        #         return arr[-1]
        # return helper_inorder(root,[]) or 0
        stack = []
        curr = root
        ct = 0
        while(curr or stack):
            while(curr):
                stack.append(curr)
                curr = curr.left
            curr = stack.pop()
            ct += 1
            if(ct == k):
                return curr.val
            curr = curr.right


