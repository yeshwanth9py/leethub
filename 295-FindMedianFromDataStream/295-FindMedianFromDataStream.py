# Last updated: 6/11/2026, 11:34:04 AM
import heapq


class MedianFinder:
    def __init__(self):
        self.small = []  #max heap
        self.large = []  #min heap

    def addNum(self, num: int) -> None:
        if(num is not None):
            heapq.heappush(self.small, -1*num)
        # checking the order
        if(self.small and self.large and -1*(self.small[0])>self.large[0]):
            pop = heapq.heappop(self.small)
            heapq.heappush(self.large, -1*pop)
        # check if length is not in the right way
        if(len(self.small)>len(self.large)+1):
            pop = heapq.heappop(self.small)
            heapq.heappush(self.large, -1*pop)
        if(len(self.small)+1<len(self.large)):
            pop = heapq.heappop(self.large)
            heapq.heappush(self.small, -1*pop)

    def findMedian(self) -> float:
        if(len(self.small)>len(self.large)):
            return -1*self.small[0]
        elif(len(self.large)>len(self.small)):
            return self.large[0]
        else:
            return ((-1*(self.small[0]))+self.large[0])/2
        

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()