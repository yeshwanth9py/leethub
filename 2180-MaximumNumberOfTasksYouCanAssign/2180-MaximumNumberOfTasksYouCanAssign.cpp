// Last updated: 6/11/2026, 11:24:15 AM
class Solution {
public:
    vector<int> tasks;
    vector<int> workers;
    int st;
    bool can_do(int mid, int pills){
        multiset<int> actasks;
        multiset<int> actwork;
        for(int i=0; i<mid; i++){
            if(i<tasks.size()) actasks.insert(tasks[i]);
            if(workers.size()-1-i>=0) actwork.insert(workers[workers.size()-1-i]);
        }

        int nop = pills;
        
        int pos = mid;
        while(pos--){
            // cout<<actwork.size()<<" ";
            int cws = *actwork.begin();
            if(cws>=*actasks.begin()){
                actwork.erase(actwork.begin());
                actasks.erase(actasks.begin());
            }else if(nop>0){
                nop--;
                auto it = actasks.upper_bound(cws+st);
                if(it == actasks.begin()){
                    return 0;
                }
                it--;
                actasks.erase(actasks.find(*it));
                actwork.erase(actwork.begin());
            }else{
                return 0;
            }
        }

        return 1;
    }


    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(workers.begin(), workers.end());
        sort(tasks.begin(), tasks.end());

        this->workers = workers;
        this->tasks = tasks;
        this->st = strength;

        int lo = 1;
        int hi = min(workers.size(), tasks.size());
        int ans = -1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(can_do(mid, pills)){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }

        return ((ans==-1)?0:ans);
    }
};