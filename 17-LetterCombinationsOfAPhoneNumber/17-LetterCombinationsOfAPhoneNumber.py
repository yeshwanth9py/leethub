# Last updated: 6/11/2026, 11:38:35 AM
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        phone = {
            1: "",
            2: "abc",
            3: "def",
            4: "ghi",
            5: "jkl",
            6: "mno",
            7: "pqrs",
            8: "tuv",
            9: "wxyz",
            0: ""
        }
        ans = []
        if(digits == ""):
            return []
        def rec(path, ind):
            # base case
            if(ind == len(digits)):
                ans.append(path)
                return
            # choice
            for ch in phone[int(digits[ind])]:
                rec(path+ch, ind+1)
        rec("", 0)
        return ans




        
