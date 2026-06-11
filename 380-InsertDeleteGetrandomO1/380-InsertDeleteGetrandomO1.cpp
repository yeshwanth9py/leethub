// Last updated: 6/11/2026, 11:33:30 AM
class RandomizedSet {
public:
    vector<int> arr;  
    unordered_map<int, int> ump; //val - idx
    int idx;
    RandomizedSet() {
        idx = 0;
        srand(time(0));
    }
    
    bool insert(int val) {
        if(ump.find(val) == ump.end() || ump[val] == -1){
            ump[val] = idx;
            arr.push_back(val);
            idx++;
            return 1;
        }else{
            return 0;
        }
    }
    
    bool remove(int val) {
        if(ump.find(val) == ump.end() || ump[val] == -1){
            return 0;
        }
        int index = ump[val];
        int va = arr.back();
        swap(arr[idx-1], arr[index]);
        arr.pop_back();
        ump[val] = -1;
        ump.erase(val);
        if(val != va) ump[va] = index;
        idx--;
        return 1;
    }

    int getRandom() {
        int d = rand();
        d = d%idx;
        return arr[d];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */