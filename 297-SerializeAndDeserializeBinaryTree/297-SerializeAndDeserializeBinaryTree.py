# Last updated: 6/11/2026, 11:34:02 AM
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str

        """
        op = []
        def dfs(node):
            if(not node):
                op.append("N")
                return
            op.append(str(node.val))
            dfs(node.left)
            dfs(node.right)
        dfs(root)
        k = ",".join(op)
        return k
        
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        # recieve the data and store it in array
        op = data.split(",")
        # define a global variable index
        self.i = 0
        def dfs():
            if(op[self.i] == "N"):
                self.i += 1
                return None
            node = TreeNode(int(op[self.i]))
            self.i += 1
            node.left = dfs()
            # i need not increase the index count here
            node.right = dfs()
            return node
            
        return dfs()





        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))