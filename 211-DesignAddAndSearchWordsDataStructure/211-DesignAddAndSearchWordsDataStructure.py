# Last updated: 6/11/2026, 11:34:48 AM
class Trienode:
    def __init__(self):
        self.children = {}
        self.eofword = False

class WordDictionary:
    def __init__(self):
        self.root = Trienode()

    def addWord(self, word: str) -> None:
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = Trienode()
            cur = cur.children[c] 
        cur.eofword = True     

    def search(self, word: str) -> bool:
        cur = self.root
        def dfs(ind,cur):
            for i in range(ind, len(word)):
                c = word[i]
                if(c == "."):
                    for char in cur.children.values():
                        if dfs(i+1,char):
                            return True
                    return False    #m1-i gave an extra tab?
                else:
                    if (c not in cur.children):
                        return False
                    cur = cur.children[c]
            return cur.eofword
        return dfs(0, cur)

# class WordDictionary:
#     def __init__(self):
#         self.root = Trienode()
#     def addWord(self, word: str) -> None:
#         cur = self.root
#         for c in word:
#             if c not in cur.children:
#                 cur.children[c] = Trienode()
#             cur = cur.children[c]
#         cur.word = True
#     def search(self, word: str) -> bool:
#         cur = self.root
#         def dfs(ind,cur):
#             # for i,c in enumerate(word[ind:]):
#             # for i in range(len(word[ind:])):
#             for i in range(ind, len(word)):
#                 c=word[i]
#                 if(c == "."):
#                     for elem in cur.children.values():  #2
#                         if(dfs(i+1,elem)):            # 1 cur.children[elem])
#                             return True
#                     return False

#                 else:
#                     if (c not in cur.children):
#                         return False
#                     cur = cur.children[c]
#                     #3 return dfs(i+1,cur)
#             return cur.word
#         return dfs(0, cur)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)