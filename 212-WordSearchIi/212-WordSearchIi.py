# Last updated: 6/11/2026, 11:34:46 AM
class TrieNode:
    def __init__(self):
        self.children = {}
        self.isend = False

    def addword(self,word):
        cur = self
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.isend = True



class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        root = TrieNode()
        for w in words:
            root.addword(w)
        
        res,vis = set(),set()
        rows,cols = len(board),len(board[0])
        def dfs(i,j,node,word):
            if(i<0 or j<0 or i>=rows or j>=cols or (i,j) in vis or board[i][j] not in node.children):
                return
            vis.add((i,j))
            node = node.children[board[i][j]]
            word = word + board[i][j]
            if(node.isend == True):
                res.add(word)

            dfs(i+1,j,node,word)
            dfs(i,j+1,node,word)
            dfs(i,j-1,node,word)
            dfs(i-1,j,node,word)

            vis.remove((i,j))

        for i in range(rows):
            for j in range(cols):
                dfs(i,j,root,"")

        return list(res)
