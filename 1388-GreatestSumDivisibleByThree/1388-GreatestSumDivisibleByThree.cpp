// Last updated: 6/11/2026, 11:28:36 AM
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        multiset<int> arr[3];
        int sum = 0;
        for(int el: nums){
            sum += el;
            arr[el%3].insert(el);
        }

        if(sum%3 == 0) return sum;

        int ex = sum%3;

        if(ex == 1){
            if(arr[1].size() == 0){
                if(arr[2].size()<=1) return 0;

                auto it = arr[2].begin();
                int p2 = *it;
                it++;
                if(it!=arr[2].end()){
                    p2 = p2+(*it);
                }
                return sum-p2;
            }else if(arr[2].size() <= 1){
                if(arr[1].size()==0) return 0;
                return sum-(*arr[1].begin());
            }

            int p1 = *(arr[1].begin());
            auto it = arr[2].begin();
            int p2 = *it;
            it++;
            if(it!=arr[2].end()){
                p2 = p2+(*it);
            }
            p1 = min(p1, p2);
            sum -= p1;
            return sum;
        }else{
            if(arr[1].size() <= 1){
                if(arr[2].size() == 0) return 0;
                int p2 = *(arr[2].begin());
                return sum-p2;
            }else if(arr[2].size() == 0){
                if(arr[1].size()<=1) return 0;
                auto it = arr[1].begin();
                int p1 = *it;
                it++;
                if(it!=arr[1].end()){
                    p1 = p1+(*it);
                }
                return sum-p1;
            }
            int p2 = *(arr[2].begin());
            auto it = arr[1].begin();
            int p1 = *it;
            it++;
            if(it!=arr[1].end()){
                p1 = p1+(*it);
            }
            p1 = min(p1, p2);
            sum -= p1;
            return sum;
        }
    }
};