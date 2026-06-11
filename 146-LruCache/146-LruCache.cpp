// Last updated: 6/11/2026, 11:35:42 AM
class LRUCache {
public:
    unordered_map<int, int> umpc;
    unordered_map<int, int> numb;
    unordered_map<int, int> getkey;
    set<int> allnums;


    int curh;
    int ni;
    int cap;
    LRUCache(int capacity) {
        ni = 0;
        cap = capacity;
        curh = 0;
    }
    
    int get(int key) {
        if(umpc.find(key)!=umpc.end()){
            int pn = numb[key];
            allnums.erase(pn);
            ni++;
            getkey.erase(pn);
            getkey[ni] = key;
            allnums.insert(ni);
            numb[key] = ni;
            return umpc[key];
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        ni++;
        if(umpc.find(key) != umpc.end()){
            int oni = numb[key];
            getkey.erase(oni);
            allnums.erase(oni);
            getkey[ni] = key;
            numb[key] = ni;
            umpc[key] = value;
            allnums.insert(ni);
        }else{
            allnums.insert(ni);
            numb[key] = ni;
            getkey[ni] = key;
            umpc[key] = value;
            curh++;
            if(curh>cap){
                int oni  = *(allnums.begin());
                allnums.erase(oni);
                int rmk = getkey[oni];
                getkey.erase(oni);
                numb.erase(rmk);
                umpc.erase(rmk);
                curh--;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */