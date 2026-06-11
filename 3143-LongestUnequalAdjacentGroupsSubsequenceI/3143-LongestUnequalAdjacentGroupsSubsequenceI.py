# Last updated: 6/11/2026, 11:20:02 AM
class Solution:
    def getWordsInLongestSubsequence(self, n: int, words: List[str], groups: List[int]) -> List[str]:
        maxv = [0]
        f_ans = []
#         def subseq(i,ans,maxv,f_ans,ct):
#             if(i==len(groups)):
#                 # print(ans)
#                 if(len(ans)>maxv[0]):               
#                     f_ans[:] = ans[:]
#                     maxv[0] = len(ans)
#                 return
                    
#             if((len(ans)==0) or (len(ans)>0 and groups[ans[-1]]!=groups[i])):
#                 ans.append(i)
#                 # print(ans)
#                 ct+=1
#                 subseq(i+1,ans,maxv,f_ans,ct)
#                 ans.pop()
#                 ct-=1
#             subseq(i+1,ans,maxv,f_ans,ct)
        
        # subseq(0,[],maxv,f_ans,0)
        
        f_ans1 = []
        temp = 0
        for i in range(len(groups)):
            if(len(f_ans1)==0):
                if(groups[i]==temp):
                    f_ans1.append(i)
            else:
                if(groups[i]!=groups[f_ans1[-1]]):
                    f_ans1.append(i)
        # print("f_ans1",f_ans1)
        temp =1
        f_ans2 = []
        for i in range(len(groups)):
            if(len(f_ans2)==0):
                if(groups[i]==temp):
                    f_ans2.append(i)
            else:
                if(groups[i]!=groups[f_ans2[-1]]):
                    f_ans2.append(i)
                    
        if(len(f_ans1)>len(f_ans2)):
            f_ans = f_ans1
        else:
            f_ans = f_ans2
            
        ans = []
        for i in f_ans:
            ans.append(words[i])
        return ans