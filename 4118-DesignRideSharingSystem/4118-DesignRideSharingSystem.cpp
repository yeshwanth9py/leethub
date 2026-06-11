// Last updated: 6/11/2026, 11:12:30 AM
#include<bits/stdc++.h>
using namespace std;

class RideSharingSystem {
public:
    vector<int> riders;
    vector<int> drivers;
    unordered_map<int, int> ump;
    RideSharingSystem() {
        riders.clear();
        drivers.clear();
        ump.clear();
    }
    
    void addRider(int riderId) {
        riders.push_back(riderId);
        ump[riderId] = 1;
    }
    
    void addDriver(int driverId) {
        drivers.push_back(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(drivers.size() > 0 && riders.size()>0){
            int e1 = drivers[0]; drivers.erase(drivers.begin());
            int e2 = riders[0]; riders.erase(riders.begin());
            ump[e2] = 0;
            return {e1, e2};
        }else{
            return {-1, -1};
        }
    }
    
    void cancelRider(int riderId) {
        if(ump[riderId]>0){
            auto it = find(riders.begin(), riders.end(), riderId);
            if(it != riders.end()){
                riders.erase(it);    
            }
            ump[riderId] = 0;
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */