// Last updated: 6/11/2026, 11:38:49 AM
class Solution {
public:
    string manacher(string s){
        string t = "";
        for(char ch: s){
            t.push_back('#');
            t += ch;
        }
        t += '#';

        int n = t.size();
        vector<int> p(n, 0);

        int l = 0;
        int r = 0;

        int maxr = 0;
        int ce = 0;
        
        for(int i=0; i<n; i++){
            if(i<r){
                p[i] = max(0, min(r-i, p[l+r-i]));
            }

            while(i+p[i]<n && i-p[i]>=0 && t[i+p[i]] == t[i-p[i]]){
                p[i]++;
            }
            
            if(i+p[i]>r){
                r = i+p[i];
                l = i-p[i];
            }
            if(p[i]-1>maxr){
                maxr = p[i]-1;
                ce = i;
            }
        }

        // cout<<maxr<<" "<<ce<<endl;

        int tstart;
        if(ce%2 == 0){
            int tc = (ce-2)/2;
            tstart = tc - ((maxr-1)/2);
            
            cout<<tc<<" "<<maxr<<" ";
            return s.substr(tstart, maxr);
        }else{
            int tc = (ce-1)/2;
            tstart = tc - ((maxr-1)/2);
            return s.substr(tstart, maxr);
        }    
    }

    
    string longestPalindrome(string s) {
        return manacher(s);
    }
};



