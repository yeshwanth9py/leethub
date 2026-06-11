// Last updated: 6/11/2026, 11:31:40 AM
//ap-1 --> use a simple array or vector of size equal to max element and mark the elements as +1 at start time and -1 at end time 
//now before booking i will iterate through entire array and check if my cum sum at any point has reached above 1 if so, i will return false


//ap-2 --> use a map(not unordered) whose key is the endtime and val is starttime so that we have a sorted list of endtimes, now
//now before adding a new slot(st, et) i will check first endtime greater than st and will check if starttime >= et or endtime is null
//then i can add slot

//in other words i will sort the list based on end times and i will check whether my current endtime>= upperbound(starttime) which is endtime in list :)

class MyCalendar {
public:
    map<int, int> mp;
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int startTime, int endTime) {
        if(mp.size() == 0){
            mp[endTime] = startTime;
            return true;
        }
        auto f_et_gt_cst = mp.upper_bound(startTime);
        if(f_et_gt_cst == mp.end() || f_et_gt_cst->second >= endTime){
            mp[endTime] = startTime;
            return true;
        }else{
            return false;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */