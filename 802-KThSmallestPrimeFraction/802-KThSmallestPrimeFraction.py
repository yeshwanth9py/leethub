# Last updated: 6/11/2026, 11:31:12 AM
class Solution:
    def kthSmallestPrimeFraction(self, arr: List[int], k: int) -> List[int]:
        arr1 = []
        for i in range(len(arr)-1):
            for j in range(i+1, len(arr)):
                f = arr[i]/arr[j]
                arr1.append([f,arr[i], arr[j]])
        arr1.sort()
        ans = arr1[k-1]
        return [ans[1], ans[2]]