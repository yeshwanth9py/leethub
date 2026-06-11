# Last updated: 6/11/2026, 11:20:18 AM
class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        ones = s.count("1")
        length = len(s)
        if(ones==1):
            temp = ""
            for i in range(length-1):
                temp += "0"
            temp += "1"
            return temp
        elif(ones>1):
            arr = []
            for i in s:
                arr.append(int(i))
            arr.sort()
            arr.reverse()
            # print(arr)
            for i in range(len(arr)-1,-1,-1):
                if(arr[i]==1):
                    arr[i],arr[len(arr)-1] = arr[len(arr)-1],arr[i]
                    break
            arr2 = [str(i) for i in arr]
            s = "".join(arr2)
            # print(k)         
        return s