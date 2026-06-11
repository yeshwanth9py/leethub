// Last updated: 6/11/2026, 11:15:08 AM
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& arr) {
        long long n = arr.size();
        long long m = arr[0].size();

        unordered_map<long long, long long> ump;
        long long ts = 0;
        for(long long i=0; i<n; i++){
            for(long long j=0; j<m; j++){
                ump[arr[i][j]] += 1;
                ts += arr[i][j];
            }
        }

        long long cs = 0;
        for(long long i=0; i<n; i++){
            for(long long j=0; j<m; j++){
                cs += arr[i][j];
            }
            if(cs == ts-cs) return 1;
        }

        cs = 0;
        for(long long j=0; j<m; j++){
            for(long long i=0; i<n; i++){
                cs += arr[i][j];
            }
            if(cs == ts - cs) return 1;
        }
        
        long long hs = 0;
        unordered_map<long long, long long> umple;
        for(long long i=0; i<n; i++){
            for(long long j=0; j<m; j++){
                hs += arr[i][j];
                ump[arr[i][j]] -= 1;
                umple[arr[i][j]] += 1;
            }
            long long rs = ts - hs;
            if(hs == rs) return 1;
            if(hs>rs){
                if(i == 0 || m == 1){
                    if(arr[0][0] == hs-rs || arr[0][m-1] == hs-rs) return 1;
                    if(m == 1 && (arr[i][0] == hs-rs)) return 1;
                }else if(umple[hs-rs]>0){
                    // cout<<hs<<" "<<rs<<endl;
                    // cout<<i<<endl;
                    return 1;
                }
            }else{
                if(i == n-2 || m == 1){
                    if(arr[n-1][0] == rs-hs || arr[n-1][m-1] == rs-hs) return 1;
                    if(m == 1 && (i+1<n && arr[i+1][0] == rs-hs)) return 1;
                }
                else if(ump[rs-hs]>0){
                    // cout<<hs<<" "<<rs<<endl;
                    // cout<<i<<" "<<endl;
                    return 1;
                }
            }
        }

        long long vs = 0;
        for(long long j=0; j<m; j++){
            // cout<<"kjh";
            for(long long i=0; i<n; i++){
                vs += arr[i][j];
                umple[arr[i][j]]--;
                ump[arr[i][j]]++;
            }
            long long rs = ts-vs;
            if(rs == vs) return 1;
            // cout<<vs<<" "<<rs<<endl;
            if(vs>rs){
                if(j == 0 || n == 1){
                    if(arr[0][0] == vs-rs || arr[n-1][0] == vs-rs) return 1;
                    if(n == 1 && (arr[0][j] == vs-rs)) return 1;
                }
                else if(ump[vs-rs]>0){
                    return 1;
                }
            }else{
                if(j == m-2 || n == 1){
                    if(arr[0][m-1] == rs-vs || arr[n-1][m-1] == rs-vs) return 1;
                    if(n == 1 && (j+1<m && arr[0][j+1] == rs-vs)) return 1;
                }else if(umple[rs-vs]>0){
                    return 1;
                }
            }
        }

        return 0;
    }
};