# Last updated: 6/11/2026, 11:38:08 AM
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []
        def combination(ind,temp,rsum,ans):
            if(rsum == 0):
                ans.append(temp.copy())
                return
            if(rsum<0 or ind<0):
                return
            temp.append(candidates[ind])
            combination(ind,temp,rsum-candidates[ind],ans)
            temp.pop()
            combination(ind-1,temp,rsum,ans)
        combination(len(candidates)-1,[],target,ans)
        return ans
            
                
                