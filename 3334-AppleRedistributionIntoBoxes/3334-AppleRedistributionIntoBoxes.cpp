// Last updated: 6/11/2026, 11:18:47 AM
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap) {
        int s = accumulate(apple.begin(), apple.end(), 0);
        sort(cap.begin(), cap.end());
        int nob = 0;
        for(int i=cap.size()-1; i>=0; i--){
            nob++;
            s-=cap[i];
            if(s<=0) return nob;
        }

        return -2;
    }
};