// Last updated: 6/11/2026, 11:11:22 AM
class Solution {
public:
    string slow;
    string shi;
    long long n;
    long long dp1[18][2][2][211][10][2];
    long long dp2[18][2][2][211][10][2];
    long long dp3[18][2][2][211][10][2];
    
    bool isinc(long long num){
        if(num == 0) return 1;
        string s = to_string(num);
        for(long long i=1; i<s.size(); i++){
            if((s[i]-'0')<=(s[i-1]-'0')) return 0;
        }
        return 1;
    }
    
    bool isdec(long long num){
        if(num == 0) return 1;
        string s = to_string(num);
        for(long long i=1; i<s.size(); i++){
            if((s[i]-'0')>=(s[i-1]-'0')) return 0;
        }
        return 1;
    }
    
    //increasing
    long long rec1(long long ind, long long tlo, long long thi, long long sum, long long pd, long long started){
        if(ind == n){
            if(isinc(sum) || isdec(sum)) return 0;
            return started==0;
        }

        if(dp1[ind][tlo][thi][sum][pd][started] != -1) return dp1[ind][tlo][thi][sum][pd][started];
        long long l = 0;
        if(tlo == 1){
            l = slow[ind]-'0';
        }

        long long r = 9;
        if(thi == 1){
            r = shi[ind]-'0';
        }

        long long ans = 0;
        for(long long i=l; i<=r; i++){
            long long ntlo = tlo;
            long long nthi = thi;

            if(i != l){
                ntlo = 0;
            }

            if(i != r){
                nthi = 0;
            }
            
            long long nstarted = started;
            if(i != 0){
                nstarted = 0;
            }
            
            if(i>pd || started == 1){
                ans += rec1(ind+1, ntlo, nthi, sum+i, i, nstarted);
            }
        }
        return dp1[ind][tlo][thi][sum][pd][started] = ans;
    }
    
    long long rec2(long long ind, long long tlo, long long thi, long long sum, long long pd, long long started){
        if(ind == n){
            if(isinc(sum) || isdec(sum)) return 0;
            return started==0;
        }

        if(dp2[ind][tlo][thi][sum][pd][started] != -1) return dp2[ind][tlo][thi][sum][pd][started];

        long long l = 0;
        if(tlo == 1){
            l = slow[ind]-'0';
        }

        long long r = 9;
        if(thi == 1){
            r = shi[ind]-'0';
        }

        long long ans = 0;
        for(long long i=l; i<=r; i++){
            long long ntlo = tlo;
            long long nthi = thi;

            if(i != l){
                ntlo = 0;
            }

            if(i != r){
                nthi = 0;
            }
            long long nstarted = started;
            if(i != 0){
                nstarted = 0;
            }
            
            if(i<pd || started == 1){
                ans += rec2(ind+1, ntlo, nthi, sum+i, i, nstarted);
            }
        }
        return dp2[ind][tlo][thi][sum][pd][started] = ans;
    }
    
    long long rec3(long long ind, long long tlo, long long thi, long long sum, long long pd, long long started){
        if(ind == n){
            if(isinc(sum) || isdec(sum)){
                // cout<<numb<<endl;
                return 1;
            }
            return 0;
        }
        
        if(dp3[ind][tlo][thi][sum][pd][started] != -1) return dp3[ind][tlo][thi][sum][pd][started];

        long long l = 0;
        if(tlo == 1){
            l = slow[ind]-'0';
        }

        long long r = 9;
        if(thi == 1){
            r = shi[ind]-'0';
        }

        long long ans = 0;
        for(long long i=l; i<=r; i++){
            long long ntlo = tlo;
            long long nthi = thi;

            if(i != l){
                ntlo = 0;
            }

            if(i != r){
                nthi = 0;
            }
            
            long long nstarted = started;
            if(i != 0){
                nstarted = 0;
            }
            
            
            ans += rec3(ind+1, ntlo, nthi, sum+i, i, nstarted);
            
        }
        
        return dp3[ind][tlo][thi][sum][pd][started] = ans;
    }

    
    long long countFancy(long long l, long long r) {
        long long ans = 0;
        
        if(r<=10){
            return r-l+1;
        }
        if(l<10){
            ans += 10-l;
            l = 10;
        }

        // if(l == r){
        //     if(isinc(l) == 1 || isdec(l) == 1){
        //         return ans+1;
        //     }
            
        // }
        
        slow = to_string(l);
        shi = to_string(r);
        memset(dp1, -1, sizeof(dp1));
        memset(dp2, -1, sizeof(dp2));
        memset(dp3, -1, sizeof(dp3));

        long long dif = shi.size()-slow.size();
        string temp = "";
        for(long long i=0; i<dif; i++){
            temp.push_back('0');
        }

        slow = temp+slow;
        n = slow.size();

        long long v1 = rec1(0, 1, 1, 0, 0, 1);
        long long v2 = rec2(0, 1, 1, 0, 0, 1);
        long long v3 = rec3(0, 1, 1, 0, 0, 1);
        
        ans += v3+v2+v1;
        
        return ans;

        
    }
};