# Last updated: 6/11/2026, 11:20:11 AM
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        dict1 = {}
        maxsize = 1
        for i in nums:
            if i in dict1:
                dict1[i] += 1
                maxsize = dict1[i]
            else:
                dict1[i] = 1
        ct = 0
        # print(dict1)
        # dp = [-1]*(maxsize+1)
        
        def fun(count,dp):
            if(count<0):
                return 100000
            if(count==0):
                return 0
            if(dp[count]!=-1):
                return dp[count]
            s1 = 1+fun(count-2,dp)
            s2 = 1+fun(count-3,dp)
            dp[count] = min(s1,s2)
            return dp[count]
        
        for i in dict1:
            dp = [-1]*(dict1[i]+1)
            ct+=fun(dict1[i],dp)
        # print(fun(ct,dp))
        if(ct>100000):
            return -1
        return ct
        
        
            