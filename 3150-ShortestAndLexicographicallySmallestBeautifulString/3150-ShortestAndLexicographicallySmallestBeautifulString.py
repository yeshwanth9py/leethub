# Last updated: 6/11/2026, 11:19:52 AM
class Solution:
#     def shortestBeautifulSubstring(self, s: str, k: int) -> str:
#         arr = []
#         #substr sum
#         cur_sum = 0
#         dict1 = {}
#         minl = 100
#         i = 0
#         while(i<len(s)):
#             cur_sum += int(s[i])
#             if(cur_sum == k and i+1<minl):
#                 arr = []
#                 arr.append(s[:i+1])
#                 dict1[cur_sum] = i
#             elif(cur_sum == k and i+1==minl):
#                 arr.append(s[:i+1])
#                 dict1[cur_sum] = i
#             if(cur_sum-k in dict1):
#                 if(i+1-dict1[cur_sum-k]<minl):
#                     arr = []
#                     arr.append(s[dict1[cur_sum-k]:i+1])
#                     minl = i+1-dict1[cur_sum-k]
#                 elif(i+1-dict1[cur_sum-k]==minl):
#                     arr.append(s[dict1[cur_sum-k]:i+1])   
#                 dict1[cur_sum] = i
#             i+=1
            
#         arr.sort()
#         print(arr)
#         if(len(arr)==0):
#             return ""
#         return arr[0]
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
            min_len = float('inf')
            result = []

            for i in range(len(s)):
                if s[i] == '1':
                    ones_count = 1
                    j = i + 1
                    while j < len(s) and ones_count < k:
                        if s[j] == '1':
                            ones_count += 1
                        j += 1

                    if ones_count == k:
                        # Found a beautiful substring
                        if j - i < min_len:
                            min_len = j - i
                            result = []
                            result.append(s[i:j])
                        elif(j - i == min_len):
                            result.append(s[i:j])
            result.sort()
            if(result == []):
                return ""
            return result[0]
            