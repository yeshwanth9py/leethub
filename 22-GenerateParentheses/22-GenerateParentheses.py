# Last updated: 6/11/2026, 11:38:27 AM
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        def rec(path, open, close):
            if(open>n):
                return
            if(close>open):
                return
            if(len(path)==2*n):
                ans.append(path)
                return
            rec(path+"(", open+1, close)
            rec(path+")", open, close+1)
        rec("", 0, 0)
        return ans