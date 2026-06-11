# Last updated: 6/11/2026, 11:36:44 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # method:1   recursive preorder traversal 
        if(root is None):
            return 0
        # ld = 1+self.maxDepth(root.left)
        # rd = 1+self.maxDepth(root.right)
        # return max(ld, rd)

        # method:2  level order traversal(dfs iterative)
        # stack = deque()
        # stack.append(root)
        # level = 0
        # while(len(stack)!=0):
        #     for i in range(len(stack)):
        #         cur = stack.popleft()
        #         if(cur.left):
        #             stack.append(cur.left)
        #         if(cur.right):
        #             stack.append(cur.right)
        #     level += 1
        # return level

        # method:3  dfs using tack(iterative)
        stack = [[root, 1]]
        # cd = 0
        while(len(stack)!= 0):
            curr = stack.pop(0)
            cn = curr[0]
            cd = curr[1]
            if(cn.left):
                stack.append([cn.left,cd+1])
            if(cn.right):
                stack.append([cn.right, cd+1])
        return cd
            

        