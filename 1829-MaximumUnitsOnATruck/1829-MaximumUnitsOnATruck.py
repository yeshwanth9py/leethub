# Last updated: 6/11/2026, 11:26:17 AM
class Solution:
    def maximumUnits(self, boxtypes: List[List[int]], truckSize: int) -> int:
        boxtypes2 = sorted(boxtypes, key=lambda x:x[1],reverse=True)
        noofboxes = 0
        boxreq = truckSize
        totval = 0
        for i in range(len(boxtypes)):
            if(boxreq!=0):
                if(boxreq>=boxtypes2[i][0]):
                    noofboxes += boxtypes2[i][0]
                    boxreq -= boxtypes2[i][0]
                    print(boxtypes2[i][0],boxtypes2[i][1])
                    totval += (boxtypes2[i][0])*(boxtypes2[i][1])
                else:
                    noofboxes += boxreq
                    totval += (boxreq)*(boxtypes2[i][1])
                    print(boxtypes2[i][0],boxtypes2[i][1])
                    boxreq = 0
                    break
        return totval