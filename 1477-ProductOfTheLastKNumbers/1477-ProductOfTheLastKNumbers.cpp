// Last updated: 6/11/2026, 11:27:54 AM
using ll = long long;
class ProductOfNumbers {
public:
    vector<ll> knums;
    int lz = 0;
    ProductOfNumbers() {
        knums.clear();
        lz = 0;
    }
    
    void add(int num) {
        if(knums.empty()){
            knums.push_back(num);
            if(num == 0){
                lz = 1;
            }
        }else{
            ll lel = knums.back();
            if(lel==0){
                knums.push_back(num);
            }else{
                ll nel = lel*num;
                knums.push_back(nel);
            }

            if(num == 0){
                lz = 1;
            }else if(lz!=0){
                lz++;
            }
        }
    }
    
    int getProduct(int k) {
        int n = knums.size();
        if(lz!=0 && k>=lz){
            return 0;
        }

        ll last = knums.back();
        if(k==n){
            return last;
        }
        
        ll tillk = knums[n-k-1];
        
        
        if(tillk==0){
            return last;
        }
        return last/tillk;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */