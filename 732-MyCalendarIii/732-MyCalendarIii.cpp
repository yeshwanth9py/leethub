// Last updated: 6/11/2026, 11:31:39 AM
class MyCalendarThree {
public:
    vector<pair<int, int>> eve;
    MyCalendarThree() {
        eve.clear();
    }

    int findkbooking(int tim){
        int i=0;
        int cnt = 0;
        int ans = 0;
        while(i<eve.size()){
            // if(eve[i].first>=tim) break;
            if(eve[i].second==0){
                cnt--;
            }else{
                cnt++;
            }
            ans = max(ans, cnt);
            i++;
        }
        return ans;
    }
    
    int book(int startTime, int endTime) {
        eve.push_back({endTime, 0});
        eve.push_back({startTime, 1});
        sort(eve.begin(), eve.end());
        int ans = findkbooking(startTime);
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */