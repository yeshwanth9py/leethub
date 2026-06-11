# Last updated: 6/11/2026, 11:37:36 AM
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        i = 0
        op = []
        intervals = sorted(intervals,key = lambda x: x[0])
        # intervals = sorted(intervals, key=lambda x: x[1])

        while(i<len(intervals)):
            if(i == len(intervals)-1):
                op.append(intervals[i])
                i+=1
            elif(intervals[i][1]<intervals[i+1][0]):
                op.append(intervals[i])
                i+=1
            else:
                j = i+1
                while(j<len(intervals) and intervals[i][1]>=intervals[j][0]):
                    intervals[i][1] = max(intervals[i][1], intervals[j][1])
                    j = j+1
                
                op.append(intervals[i])
                i = j
                # if(i==len(intervals)-1):
                #     return op
            
        return op