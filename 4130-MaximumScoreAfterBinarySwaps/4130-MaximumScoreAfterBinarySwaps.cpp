// Last updated: 6/11/2026, 11:12:16 AM
class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long n = s.size();
        long long f1 = 0;
        long long f2 = n-1;
        long long sm = 0;
        
        for(long long i=0; i<n; i++){
            if(s[i] == '1'){
                f1++;
                sm += nums[i];
            }else{
                break;
            }
        }

        for(long long i=n-1; i>=0; i--){
            if(s[i] == '0'){
                f2--;
            }else{
                break;
            }
        }

        cout<<f1<<" "<<f2<<endl;
        if(f1>f2) return sm;
        
        priority_queue<long long> pq;
        long long n1 = 0;
        
        for(long long i=f1; i<=f2; i++){
            if(s[i] == '1'){
                pq.push(nums[i]);
                sm += pq.top(); pq.pop();
            }else{
                pq.push(nums[i]);
            }
        }

        // while(n1-- && pq.size()>0){
        //     sm += pq.top(); pq.pop();
        // }

        return sm;
        
    }
};