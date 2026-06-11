// Last updated: 6/11/2026, 11:22:19 AM
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& arr) {
        priority_queue<long long, vector<long long>, greater<long long>> avail;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> used;

        for(long long i=0; i<n; i++) avail.push(i);

        sort(arr.begin(), arr.end());

        vector<long long> ans(n, 0);

        for(auto m: arr){
            long long s = m[0];
            long long e = m[1];
            while(!used.empty() && used.top().first<=s){
                auto [et, rm] = used.top(); used.pop();
                avail.push(rm);
            }

            if(avail.size()==0){
                auto [et, rm] = used.top(); used.pop();
                long long net = 1LL*et+1LL*(e-s);
                used.push({net, rm});
                // cout<<et<<" "<<rm<<", ";
                ans[rm]++;
            }else{
                long long rm = avail.top(); avail.pop();
                used.push({e, rm});
                // cout<<s<<" "<<rm<<", ";
                ans[rm]++;
            }
        }

        long long asans = 0;
        for(long long i=0; i<n; i++){
            // cout<<ans[i]<<" ";
            if(ans[asans]<ans[i]){
                asans = i;
            }
        }
        cout<<endl;
        return asans;   

    }
};