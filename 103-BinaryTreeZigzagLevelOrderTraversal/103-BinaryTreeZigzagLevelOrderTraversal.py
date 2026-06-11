# Last updated: 6/11/2026, 11:36:39 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if(root is None):
            return 
        queue = [root]
        ans = []
        ct = 1
        while(len(queue)!=0):
            level_el = []
            for _ in range(len(queue)):
                cur = queue.pop(0)
                if(cur is None):
                    continue
                if(cur.right):
                    queue.append(cur.right)
                if(cur.left):
                    queue.append(cur.left)
                level_el.append(cur.val)
            if(ct%2 == 0):
                ans.append(level_el)
            else:             
                level_el.reverse()
                ans.append(level_el)
            ct += 1
        return ans