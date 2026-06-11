# Last updated: 6/11/2026, 11:19:49 AM
class Solution:
    def minProcessingTime(self, processorTime: List[int], tasks: List[int]) -> int:
        processorTime.sort(reverse=True)
        tasks.sort()
        time=0
        j = 0
        for i in range(len(processorTime)):
            ct = 1
            while(ct<=4 and j<len(tasks)):
                time = max(processorTime[i]+tasks[j],time)
                print(time)
                j+=1
                ct=ct+1
       
        return time