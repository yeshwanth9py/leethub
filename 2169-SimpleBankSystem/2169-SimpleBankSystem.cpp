// Last updated: 6/11/2026, 11:24:23 AM
class Bank {
public:
    vector<long long> arr;
    Bank(vector<long long>& balance) {
        arr = balance;
    }
    
    bool transfer(int ac1, int ac2, long long money) {
        if(ac1-1<0 || ac1-1>=arr.size() || ac2-1<0 || ac2-1>=arr.size()) return 0;
        if(arr[ac1-1]>=money){
            arr[ac2-1] += money;
            arr[ac1-1] -= money;
            return 1;
        }
        return 0;
    }
    
    bool deposit(int ac1, long long money) {
        if(ac1-1<0 || ac1-1>=arr.size()) return 0;
        arr[ac1-1] += money;
        return 1;
    }
    
    bool withdraw(int ac1, long long money) {
        if(ac1-1<0 || ac1-1>=arr.size()) return 0;
        if(arr[ac1-1]>=money){
            arr[ac1-1] -= money;
            return 1;
        }
        return 0;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */