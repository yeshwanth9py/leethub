# Last updated: 6/11/2026, 11:20:16 AM
class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        ct = 0
        m1,m2 = abs(fx-sx),abs(fy-sy)
        tempx = max(m1,m2)
        tempn = min(m1,m2)
        m1 = tempx
        m2=tempn
        if(m1==0 and m2==0):
            if(t==0 or t>=2):
                return 1
            return 0
        
        ct = m1
        if (ct<=t):
            return 1
        else:
            return 0
        return 0
#         m1,m2 = fx-sx,fy-sy
#         tempx = max(m1,m2)
#         tempn = min(m1,m2)
#         m1 = tempx
#         m2=tempn
#         if(m1==0 and m2==0 and t>=2):
#             return 1
#         elif(t>m2 and t>m1 and t<=m1+m2):
#             return 1
#         elif(t==m1+m2):
#             return 1
#         else:
#             return 0
            
            