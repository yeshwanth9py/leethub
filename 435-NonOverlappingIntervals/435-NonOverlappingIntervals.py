# Last updated: 6/11/2026, 11:33:07 AM
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key=lambda x: x[0])
        last = intervals[0][1]
        rem = 0
        for i in range(1,len(intervals)):
            if(last<=intervals[i][0]):
                last = intervals[i][1]
                continue
            else:
                rem += 1
                last = min(last,intervals[i][1])
        return rem