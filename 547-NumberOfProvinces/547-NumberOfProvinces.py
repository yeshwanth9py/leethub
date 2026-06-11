# Last updated: 6/11/2026, 11:32:40 AM
class Solution:
    def findCircleNum(self, isConnected: List[List[int]]) -> int:
        nodes = len(isConnected)
        visited = set()
        comp = [0]
        def dfs(node):
            if(node not in visited):
                visited.add(node)
                for i in range(len(isConnected)):
                    if(i!=node and isConnected[node][i]==1):
                        dfs(i)


        for i in range(nodes):
            if(i not in visited):
                dfs(i)
                comp[0] += 1
                
        return comp[0]
        