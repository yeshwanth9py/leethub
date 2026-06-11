// Last updated: 6/11/2026, 11:13:15 AM
class Solution {
public:
    vector<int> giv;
    int n;
    vector<int> arr;
    unordered_map<int, int> getfacts(int nu){
        unordered_map<int, int> ump;
        for(int i=2; i*i<=nu; i++){
            if(nu%i == 0){
                int cnt = 0;
                while(nu%i == 0){
                    nu = nu/i;
                    cnt++;
                }
                ump[i] += cnt;
            }
        }
        if(nu){
            ump[nu]++;
        }
        return ump;
    }
    int dp[21][51][51][51];
    int rec(int idx, int no2, int no3, int no5){
        if(no2>=21 || no3>=21 || no5>=21) return 0;
        if(idx == n){
            if(no2 == 0 && no3 == 0 && no5 == 0) return 1;
            return 0;
        }

        if(dp[idx][no2+19][no3+19][no5+19]!= -1){
            return dp[idx][no2+19][no3+19][no5+19];
        }

        int way1 = rec(idx+1, no2, no3, no5);
        unordered_map<int, int> getf = getfacts(arr[idx]);

        int nno2 = no2;
        int nno3 = no3;
        int nno5 = no5;
        for(auto el: getf){
            if(el.first == 2){
                nno2+=el.second;
            }else if(el.first == 3){
                nno3 += el.second;
            }else if(el.first == 5){
                nno5 += el.second;
            }
        }
        
        int way2 = rec(idx+1, nno2, nno3, nno5);
        for(auto el: getf){
            if(el.first == 2){
                nno2-=2*el.second;
            }else if(el.first == 3){
                nno3 -= 2*el.second;
            }else if(el.first == 5){
                nno5 -= 2*el.second;
            }
        }
        
        int way3 = rec(idx+1, nno2, nno3, nno5);

        return dp[idx][no2+19][no3+19][no5+19] = way1+way2+way3;
    }
    
    int countSequences(vector<int>& nums, long long k) {
        unordered_map<long long, int> ump;
        arr = nums;
        n = arr.size();
        long long dk = k;
        for(long long i=2; 1LL*i*i<=k; i++){
            if(dk%i == 0){
                int cnt = 0;
                while(dk%i == 0){
                    dk = dk/i;
                    cnt++;
                }
                ump[i] += cnt;
            }
        }
        if(dk){
            ump[dk]++;
        }
        int no2 = 0;
        int no3 = 0;
        int no5 = 0;
        for(auto el: ump){
            if(el.first>6){
                cout<<el.first<<" ";
                return 0;
            }
            if(el.first == 2){
                no2 += el.second;
            }else if(el.first == 3){
                no3 += el.second;
            }else if(el.first == 5){
                no5 += el.second;
            }
        }

        memset(dp, -1, sizeof(dp));

        return rec(0, no2, no3, no5);
        
    }
};