# Last updated: 6/11/2026, 11:19:33 AM
class Solution:
    def findKOr(self, nums: List[int], k: int) -> int:
        fatdict = {}
        ans = set()
        for i in range(len(nums)):
            cur = bin(nums[i])[2:]
            b=0
            while(b<len(cur)): 
                # print(bin(nums[i]),bin(1<<b),nums[i] & (1<<b))
                if((nums[i] & (1<<b))!=0):
                    # print(b,nums[i])
                    if(b in fatdict):
                        fatdict[b][0] += 1
                        if(fatdict[b][0] >= k):
                            ans.add(b)
                        fatdict[b].append(nums[i])
                    else:
                        fatdict[b] = [1,nums[i]]
                        if(fatdict[b][0] >= k):
                            ans.add(b)
                b+=1
        print(fatdict,ans)
        ans2 = 0
        for i in ans:
            ans2 += 2**i
            
        return ans2