// Last updated: 6/11/2026, 11:16:13 AM
class Solution {
public:
    bool check(vector<vector<int>>& sqs, double md){
        double ar1 = 0;
        double ar2 = 0;
        for(int i=0; i<sqs.size(); i++){
            double dy = sqs[i][1];
            double ty = sqs[i][1]+sqs[i][2];
            double xl = sqs[i][2];
            if(md>=ty){
                ar2 += (1.0*xl*xl);
            }else if(md<=dy){
                ar1 += (1.0*xl*xl);
            }else{
                ar1 += 1.0*xl*(abs(ty-md));
                ar2 += 1.0*xl*(abs(md-dy));
            }
        }

        return ar1<=ar2;
    }

    double separateSquares(vector<vector<int>>& sqs) {
        double lo = -1e9;
        double hi = 1e9;
        double ans = -1;
        for(int i=0; i<60; i++){
            double mid = (lo+hi)/2.0;
            cout<<mid<<" ";
            if(check(sqs, mid)){  //mid must increase
                hi = mid;
            }else{
                ans = mid;
                lo = mid;
            }
        }

        return ans;
    }
};