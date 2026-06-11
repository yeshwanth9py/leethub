// Last updated: 6/11/2026, 11:19:16 AM
class Solution {
public:
    vector<vector<long long>> mat;
    long long minimumCost(string source, string target, vector<char>& orig, vector<char>& chan, vector<int>& cost) {
        mat.resize(26, vector<long long>(26, 1e18));
        for(long long i=0; i<26; i++) mat[i][i] = 0;

        long long m = chan.size();

        for(long long i=0; i<m; i++){
            long long u = orig[i]-'a';
            long long v = chan[i]-'a';
            mat[u][v] = min(mat[u][v], 1LL*cost[i]);
        }

        for(long long k=0; k<26; k++){
            for(long long i=0; i<26; i++){
                for(long long j=0; j<26; j++){
                    if(mat[i][k]!=1e9 && mat[k][j]!=1e9){
                        mat[i][j] = min(mat[i][j], mat[i][k]+mat[k][j]);
                    }
                }
            }
        }

        long long tot = 0;

        for(long long i=0; i<source.size(); i++){
            long long u = source[i]-'a';
            long long v = target[i]-'a';
            if(mat[u][v]>=1e8) return -1;
            tot += mat[u][v];
        }

        

        return tot;

    }
};