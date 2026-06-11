# Last updated: 6/11/2026, 11:26:44 AM
class Solution:
    def specialArray(self, arr: List[int]) -> int:
        arr.sort()
        for i in range(len(arr)+1):
            for j in range(len(arr)):
                if(arr[j]>=i and len(arr)-j == i):
                    print(i,j)
                    return i
                elif(arr[j]>=i and len(arr)-j != i):
                    break
        return -1


