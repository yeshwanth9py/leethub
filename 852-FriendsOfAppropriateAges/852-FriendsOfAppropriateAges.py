# Last updated: 6/11/2026, 11:30:53 AM
class Solution:
    def numFriendRequests(self, ages: List[int]) -> int:
        arr = [0]*122

        for i in ages:
            arr[i] += 1

        cnt = 0
        for i in range(1, 122):
            for j in range(1, 122):
                if((j <= 0.5*i + 7) or (j>i) or (j>100 and i<100)):
                    continue
                else:  
                    cnt += (arr[i]*arr[j]) 
                    if(i == j):
                        cnt -= arr[i]
        return cnt