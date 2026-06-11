# Last updated: 6/11/2026, 11:33:16 AM
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq_dict = {}
        i = j = 0
        maxfreq = 0
        maxlen = 1
        while(j<len(s)):
            freq_dict[s[j]] = freq_dict.get(s[j], 0) + 1
            maxfreq = max(maxfreq, freq_dict[s[j]])

            while(j-i+1 - maxfreq > k):
                freq_dict[s[i]] -= 1
                maxfreq = max(freq_dict.values())
                i += 1
            
            maxlen = max(maxlen, j-i+1)
            j += 1
        return maxlen



