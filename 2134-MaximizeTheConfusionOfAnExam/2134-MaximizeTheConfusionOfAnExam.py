# Last updated: 6/11/2026, 11:24:56 AM
class Solution:
    def maxConsecutiveAnswers(self, ans: str, k: int) -> int:
        
        # t to f
        def fun(chr):
            l = 0
            cnt = res = 0
            for r in range(len(ans)):
                if(ans[r] == chr):  
                    cnt += 1
                while(cnt>k):
                    if(ans[l] == chr):
                        cnt -= 1
                    l += 1
                
                res = max(res, r-l+1)
            return res
        return max(fun("T"), fun("F"))