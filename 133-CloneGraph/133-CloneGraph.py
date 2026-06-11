# Last updated: 6/11/2026, 11:35:58 AM
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional
class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        hash_map = {}
        def bfs(cur):
            if(cur is None):
                return
            if(cur in hash_map):
                return hash_map[cur]

            cur_d = Node(cur.val)
            hash_map[cur] = cur_d

            for child in cur.neighbors:
                cur_d.neighbors.append(bfs(child))

            return cur_d

        return bfs(node)

            