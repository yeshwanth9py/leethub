# Last updated: 6/11/2026, 11:19:42 AM
class Solution:
    def lastVisitedIntegers(self, words: List[str]) -> List[int]:
        ints_visited = []
        prevs_visited = []
        i = 0
        ans = []
        while(i<len(words)):
            if(words[i] != "prev"):
                if(len(prevs_visited)!=0):
                    for j in range(len(prevs_visited)):
                        if(j<len(ints_visited)):
                            ans.append(int(ints_visited[j]))
                        else:
                            ans.append(-1)
                    prevs_visited = []
                ints_visited.insert(0,words[i])
                # print(ints_visited)
            else:
                prevs_visited.append(words[i])
                # print(prevs_visited)
            i=i+1
        if(len(prevs_visited)!=0):
            for j in range(len(prevs_visited)):
                if(j<len(ints_visited)):
                    ans.append(int(ints_visited[j]))
                else:
                    ans.append(-1)
        return ans
                
                