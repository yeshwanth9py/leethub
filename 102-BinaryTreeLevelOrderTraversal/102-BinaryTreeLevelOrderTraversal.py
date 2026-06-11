# Last updated: 6/11/2026, 11:36:47 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # bfs or level order traversal
        if root is None:
            return []
        ans = []
        queue = [root]
        while(len(queue)>=1):
            temp = []
            for i in range(len(queue)):
                cur = queue.pop(0)
                temp.append(cur.val)
                if(cur.left):
                    queue.append(cur.left)
                if(cur.right):
                    queue.append(cur.right)
            ans.append(temp)
        return ans
    

                


            

            
        