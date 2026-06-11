# Last updated: 6/11/2026, 11:31:48 AM
class Solution:
    def asteroidCollision(self, arr: List[int]) -> List[int]:
        
        st = []
        i = 0
        while(i<len(arr)):
            print(i)
            if(arr[i]>0):
                st.append(arr[i])
                i=i+1 #mistake-1
            else:
                if(len(st)==0):
                    st.append(arr[i])
                    i+=1
                    continue
                el = st[-1]
                if(el<0):
                    st.append(arr[i])
                    i+=1
                    continue
                elif(abs(el) == abs(arr[i])):
                    st.pop()
                    i+=1
                    continue
                elif(abs(el)>abs(arr[i])):
                    i+=1
                    continue
                else:
                    st.pop()
        print(st)
        return st

                