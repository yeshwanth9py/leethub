# Last updated: 6/11/2026, 11:34:58 AM
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # 1:- form an adjacency list
        adj_list = {i:[] for i in range(numCourses)}

        # 2:- updating the adjacency list
        for i,j in prerequisites:
            adj_list[i].append(j)

        # 3:-creating a visited set to keep a track of all elements
        visited = set()

        # 4:-running a dfs in the adjacency list
        def dfs(el):
            if(el in visited):
                return False
            
            if(adj_list[el] == []):
                return True     

            visited.add(el)     

            for child in adj_list[el]:
                if(dfs(child) == False):
                    return False
            
            visited.remove(el)
            adj_list[el] = []
            return True

        # 5:- run a dfs for all the nodes as graph can be smts disconnected
        for i in range(numCourses):
            if(dfs(i)==False):
                return False

        return True
        
        
                
            
