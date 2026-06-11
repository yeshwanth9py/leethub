// Last updated: 6/11/2026, 11:15:58 AM
class Solution {
public:
    bool check(int num, vector<int>& original, vector<vector<int>>& bounds){
        int prevnum = num;
        // cout<<num<<": ";
        for(int i=1; i<original.size(); i++){
            int diff = original[i]-original[i-1];
            int nextnum = prevnum+diff;
            // cout<<nextnum<<", ";
            if(bounds[i][0]>nextnum || bounds[i][1]<nextnum){
                // cout<<"f"<<endl;
                return false;
            }
            
            prevnum = nextnum;
        }

        // cout<<"t"<<endl;

        return true;
    }
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int lo = bounds[0][0];
        int hi = bounds[0][1];
        int ans1 = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid, original, bounds)){
                ans1 = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        // cout<<"ans1 "<<ans1<<endl;

        hi = ans1;

        if(ans1 == -1){
            hi = bounds[0][1];
        }

        lo = bounds[0][0];
        
        int ans2 = -1;

        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid, original, bounds)){
                ans2 = mid;
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
       
        // cout<<"ans2:- "<<ans2<<endl;
        if(ans1 == -1 && ans2 != -1){
            lo = ans2;
            hi =  bounds[0][1];
            int ans3 = -1;
    
            while(lo<=hi){
                int mid = (lo+hi)/2;
                if(check(mid, original, bounds)){
                    ans3 = mid;
                    lo = mid+1;
                }else{
                    hi = mid-1;
                }
            }

            // cout<<"ans3 "<<ans3<<endl;

            return ans3-ans2+1;
        }


        if(ans1 == -1 && ans2 == -1){
            return 0;
        }

        return ans1-ans2+1;

        

        
    }
};