// Last updated: 6/11/2026, 11:22:43 AM
class NumberContainers {
public:
    unordered_map<int, int> indpos;
    unordered_map<int, set<int>> posind;
    NumberContainers() {
        indpos.clear();
        posind.clear();
    }
    
    void change(int index, int number) {
        if(indpos.find(index)!=indpos.end()){
            posind[indpos[index]].erase(index);
        }
        indpos[index] = number;
        posind[number].insert(index);
    }
    
    int find(int number) {
        if(posind.find(number)!=posind.end() && posind[number].size()>0){
            return *(posind[number].begin());
        }else{
            return -1;
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */