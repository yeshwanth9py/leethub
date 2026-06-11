// Last updated: 6/11/2026, 11:33:01 AM



class LFUCache {
public:
    unordered_map<int, int> freq;
    unordered_map<int, int> useno;
    unordered_map<int, int> getval;
    struct cmp {
        bool operator()(const vector<int>& a, const vector<int>& b) const {
            if (a[0] != b[0]) return a[0] < b[0];
            if (a[1] != b[1]) return a[1] < b[1];
            return a[2] < b[2];
        }
    };

    multiset<vector<int>, cmp> ms;
    int curc;
    int use;

    int cap;
    LFUCache(int capacity) {
        curc = 0;
        cap = capacity;
        use = 0;
    }
    
    int get(int key) {
        if(getval.find(key) == getval.end()){
            return -1;
        }else{
            int curv = getval[key];
            int curuse = useno[key];
            int curf = freq[key];
            use++;
            ms.erase({curf, curuse, key});
            ms.insert({curf+1, use, key});
            useno[key] = use;
            freq[key] = curf+1;
            return curv;
        }
    }
    
    void put(int key, int value) {
        if(getval.find(key) == getval.end()){
            curc++;
            if(curc > cap){
                auto tel = *ms.begin();
                int k = tel[2];
                useno.erase(k);
                freq.erase(k);
                getval.erase(k);
                ms.erase(ms.begin());
                curc--;
            }
            use++;
            getval[key] = value;
            useno[key] = use;
            freq[key] = 1;
            ms.insert({1, use, key});
        }else{
            use++;
            int pval = getval[key];
            int puse = useno[key];
            int pfreq = freq[key];
            ms.erase({pfreq, puse, key});
            ms.insert({pfreq+1, use, key});
            getval[key] = value;
            useno[key] = use;
            freq[key] = pfreq+1;
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */