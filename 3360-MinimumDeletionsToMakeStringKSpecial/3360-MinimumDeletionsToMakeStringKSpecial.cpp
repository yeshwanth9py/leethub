// Last updated: 6/11/2026, 11:18:39 AM
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> ump;
        vector<int> freqs;

        for(char ch: word){
            ump[ch]++;
        }

        for(auto el: ump){
            freqs.push_back(el.second);
        }

        sort(freqs.begin(), freqs.end());

        int sz = freqs.size();
        vector<int> prefix(sz+1, 0);
        vector<int> suffix(sz+1, 0);

        prefix[0] = freqs[0];

        for(int i=1; i<sz; i++){
            prefix[i] = prefix[i-1] + freqs[i];
        }
        prefix[sz] += prefix[sz-1];

        suffix[sz-1] = freqs[sz-1];
        for(int i=sz-2; i>=0; i--){
            suffix[i] = suffix[i+1] + freqs[i];
        }

        int mindel = word.size();
        // 2 4 6 10 15  5
        for(int i=0; i<freqs.size(); i++){
            int num = freqs[i];
            int min_num = freqs[i];
            int max_num = freqs[i]+k;

            int it1 = lower_bound(freqs.begin(), freqs.end(), min_num)-freqs.begin();
            int it2 = upper_bound(freqs.begin(), freqs.end(), max_num)-freqs.begin();
            
            
            it1--;

            int curd = 0;
            if(it2<sz){
                // cout<<abs(suffix[it2] - max_num*(sz-it2))<<" ";
                curd += abs(suffix[it2] - max_num*(sz-it2));
            }

            if(it1>=0){
                // cout<<prefix[it1]<<" ";
                curd += prefix[it1];
            }

            // cout<<endl;

            mindel = min(mindel, curd);
        }

        return mindel;
    }
};