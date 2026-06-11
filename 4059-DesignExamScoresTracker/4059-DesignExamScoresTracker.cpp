// Last updated: 6/11/2026, 11:13:21 AM
class ExamTracker {
public:
    long long id;
    map<long long, long long> cmp;
    vector<long long> allsc;
    vector<long long> prefs;
    ExamTracker() {
        id = 0;
        cmp.clear();
        allsc.clear();
        prefs.clear();
    }
    
    void record(int time, int score) {
        cmp[time] = id;
        id++;
        allsc.push_back(score);
        long long pr = ((prefs.size()>0)?prefs.back():0);
        prefs.push_back(pr+score);
    }
    
    long long totalScore(int startTime, int endTime) {
        auto itind1 = cmp.lower_bound(startTime);
        auto itind2 = cmp.upper_bound(endTime);
        itind2--;
        if(itind1->first >= startTime && itind2->first<=endTime && itind2->second<prefs.size()){
            long long ind1 = itind1->second;
            long long ind2 = itind2->second;
            return prefs[ind2]-((ind1-1>=0)?prefs[ind1-1]:0);
        }else{
            return 0;
        }
        
        
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */