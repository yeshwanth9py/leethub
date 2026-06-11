# Last updated: 6/11/2026, 11:37:49 AM
class Solution:
    def myPow(self, x: float, n: int) -> float:
        def fun(x,n):
            if(n==0):
                return 1
            elif(n==1):
                return x
            else:
                if(n%2 == 0):
                    return fun(x*x,n//2)
                else:
                    return x*fun(x,n-1)
        if(n<0):
            x = 1/x
            n = -n
            return fun(x,n)
        else:
            return fun(x,n)