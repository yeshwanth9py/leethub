# Last updated: 6/11/2026, 11:30:26 AM
class Solution:
    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        left = 0
        tokens.sort()
        right = len(tokens)-1
        score = 0
        maxsc = 0
        while(left<=right):
            if(power>=tokens[left]):
                score+= 1
                power -= tokens[left]
                left += 1
                maxsc = max(maxsc, score)
            elif(score>=1):
                score -= 1
                power += tokens[right]
                right -= 1
            else:
                break
            
        return maxsc
            