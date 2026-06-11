# Last updated: 6/11/2026, 11:36:23 AM
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        # update = [root.val]
        # def helper(root,update):
        #     if(root is None):
        #         # testcase:- [-3] is not passing
        #         return
        #     l_st_sum = helper(root.left, update)
        #     r_st_sum = helper(root.right, update)
        #     if(l_st_sum == None and r_st_sum == None):
        #         update[0]  = max(update[0], root.val)
        #         return root.val
        #     if(l_st_sum is None):
        #         update[0] = max(update[0],r_st_sum+root.val,r_st_sum,root.val)
        #         return r_st_sum+root.val
        #     elif(r_st_sum is None):
        #         update[0] = max(update[0],l_st_sum+root.val,l_st_sum, root.val)
        #         return l_st_sum+root.val
        #     else:
        #         update[0] = max(update[0],l_st_sum+r_st_sum+root.val,l_st_sum+root.val,r_st_sum+root.val,l_st_sum,r_st_sum, root.val)
        #         if(l_st_sum == None):
        #             l_st_sum = 0
        #         if(r_st_sum == None):
        #             r_st_sum =0
        #         return max(l_st_sum,r_st_sum)+root.val
        # helper(root,update)
        # return update[0]
        max_res = [root.val]
        def helper(root, max_res):
            if(root is None):
                return 0
            left_sum = helper(root.left,max_res)
            right_sum = helper(root.right, max_res)
            if(left_sum<0):
                left_sum = 0
            if(right_sum<0):
                right_sum = 0
            max_res[0] = max(max_res[0],left_sum+right_sum+root.val)
            return root.val+max(left_sum,right_sum)
        helper(root, max_res)
        return max_res[0]
