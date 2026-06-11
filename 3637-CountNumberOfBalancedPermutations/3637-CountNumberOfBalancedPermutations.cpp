// Last updated: 6/11/2026, 11:17:13 AM

using ll = long long;
class Solution {
public:
    ll reqs;
    vector<int> freq;
    ll numer;
    ll dp[81];
    ll dp3[10][42][420];
    ll dp2[81];
    ll static const mod = 1e9+7;
    ll inv(ll num, ll pow = mod-2){
        if(pow == 0) return 1;
        if(pow == 1) return num;
        if(pow%2 == 0){
            ll ans = inv(num, pow/2);
            return (ans%mod*ans%mod)%mod;
        }else{
            return (num%mod*inv(num, pow-1)%mod)%mod;
        }
    }

    ll fact(int num){
        if(num == 0 || num == 1){
            return 1;
        }
        if(dp[num]!=-1){
            return dp[num];
        }
        return dp[num] = (num%mod*(fact(num-1))%mod)%mod;
    }

    void precompute(){
        for(int i=0; i<=80; i++){
            dp2[i] = inv(fact(i));
        }
    }

    int backtrackcount(int digit, int cntevepos, int sum){
        if(digit == 10){
            if(cntevepos == 0 && sum == reqs) return numer;
            return 0;
        }

        if(dp3[digit][cntevepos][sum]!=-1){
            return dp3[digit][cntevepos][sum];
        }
        ll ways = 0;
        for(int f=0; f<=min(freq[digit], cntevepos); f++){
            ll eveposd = 1LL*dp2[f]%mod;
            ll oddposd = 1LL*dp2[freq[digit]-f]%mod;
            ways += (1LL*(eveposd)%mod*(oddposd)%mod*(backtrackcount(digit+1, cntevepos-f, sum+(digit)*f)%mod)%mod)%mod;
            ways %= mod;
        }
        return dp3[digit][cntevepos][sum] = ways;
    }

    int countBalancedPermutations(string num) {
        ll sum = 0;
        freq.resize(10, 0);
        memset(dp, -1, sizeof(dp));
        memset(dp3, -1, sizeof(dp3));
        precompute();
        for(int i=0; i<num.length(); i++){
            sum += (num[i]-'0');
            freq[num[i]-'0']++;
        }

        if(sum%2 != 0){
            return 0;
        }
        reqs = sum/2;
        int n = num.length();

        ll cntevepos = (n+1)/2;
        numer = (fact(n/2)%mod*fact((n+1)/2)%mod)%mod;

        return backtrackcount(0, cntevepos, 0)%mod;
        
    }
};