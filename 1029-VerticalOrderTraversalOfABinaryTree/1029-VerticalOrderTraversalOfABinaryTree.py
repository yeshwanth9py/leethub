# Last updated: 6/11/2026, 11:29:57 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import defaultdict

def fun(l):
    print(l)

class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        v=h=0
        queue = [[root,v,h]]
        verticals = defaultdict(list)
        while(len(queue)>0):
            level_el = []
            for _ in range(len(queue)):
                cur = queue.pop(0)
                v = cur[1]
                h = cur[2]
                verticals[cur[1]].append([cur[2],cur[0].val])  #v:[[h,ele]]
                if(cur[0].left):
                    queue.append([cur[0].left,v-1,h+1])
                if(cur[0].right):
                    queue.append([cur[0].right,v+1,h+1])
        verticals = dict(verticals)
        verticals = list(sorted(verticals.items()))
        stack = []
        for i in range(len(verticals)):
            anmol = sorted(verticals[i][1], key=lambda x: (x[0],x[1]))
            temp = []
            for j in anmol:
                temp.append(j[1])
            stack.append(temp)
        return stack


    
