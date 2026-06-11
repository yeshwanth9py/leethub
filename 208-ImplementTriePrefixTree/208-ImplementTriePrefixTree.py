# Last updated: 6/11/2026, 11:34:57 AM
class TrieNode:
    def __init__(self):
        self.children = {} #can be dictionary of all 26 letters or an array of 26 letters
        self.endofword = False

class Trie:
    def __init__(self):
        self.head = TrieNode()
    def insert(self, word: str) -> None:
        cur = self.head
        for c in word:
            if c in cur.children:
                cur = cur.children[c]
            else:
                node = TrieNode()
                cur.children[c] = node
                cur = node # or cur = cur.children[c]
        cur.endofword = True

    def search(self, word: str) -> bool:
        cur = self.head
        for c in word:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        return cur.endofword

    def startsWith(self, prefix: str) -> bool:
        cur = self.head
        for c in prefix:
            if c in cur.children:
                cur = cur.children[c]
            else:
                return False
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)