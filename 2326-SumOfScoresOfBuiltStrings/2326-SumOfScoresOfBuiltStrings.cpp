// Last updated: 6/11/2026, 11:23:08 AM
class Solution {
public:
    // int getkmp(string &s){
    //     int n = s.size();
    //     vector<int> kmp(n+1, -1);
    //     int i=0;
    //     int j=-1;
    //     while(i<n){
    //         while(j!=-1 && s[i]!=s[j]) j = kmp[j];
    //         i++; j++;
    //         kmp[i] = j;
    //     }
    //     return kmp[n];
    // }

    long long getz(string &s){
        long long n = s.size();
        vector<long long> z(n, 0);
        z[0] = n;
        long long l = 0;
        long long r = 0;
        for(long long i=1; i<n; i++){
            if(i<r){
                z[i] = z[i-l];
                if(i+z[i]>r){
                    z[i] = r-i;
                }
            }
            while(z[i]+i<n && s[z[i]] == s[z[i]+i]) z[i]++;
            if(i+z[i]>r){
                l = i;
                r = i+z[i];
            }
        }

        return accumulate(z.begin(), z.end(), 0LL);

    }

    long long sumScores(string s) {
        long long l = getz(s);
        // cout<<l<<endl;
        
        return l;
    }
};





















