# Last updated: 6/11/2026, 11:34:30 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # if(root is None):
        #     return None
        # if(root.val == p.val or root.val == q.val):  #mistake:- not knowing p and q are treenodes and not values
        #     return root
        # left = self.lowestCommonAncestor(root.left, p ,q)
        # right = self.lowestCommonAncestor(root.right, p, q)
        # if(right is None):
        #     return left
        # if(left is None):
        #     return right
        # if(left and right):
        #     return root
        # if(left is None and right is None):
        #     return None
        # print(left,right)
        if(root is None):
            return None
        cur = root
        while(cur):
            if(p.val>cur.val and q.val>cur.val):
                cur = cur.right
            elif(p.val<cur.val and q.val<cur.val):
                cur = cur.left
            else:
                return cur

