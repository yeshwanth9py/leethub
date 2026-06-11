// Last updated: 6/11/2026, 11:29:48 AM
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int op1 =  tops[0];
        int n = tops.size();
        bool pos = 1;
        // bool pos2 = 1;
        int mv1 = 0;  //top
        int mv2 = bottoms[0] != op1;  //bottom
        for(int i=1; i<n; i++){
            if(tops[i] != op1){
                if(bottoms[i] == op1){
                    mv1++;
                }else{
                    pos = 0;
                    break;
                }   
            }
            if(bottoms[i] != op1){
                if(tops[i] == op1){
                    mv2++;
                }else{
                    pos = 0;
                    break;
                }
            }
        }

        if(pos){
            return min(mv1, mv2);
        }


        pos = 1;
        mv1 = 0;
        
        int op2 = bottoms[0];
        mv2 = tops[0] != op2;
        for(int i=1; i<n; i++){
            if(bottoms[i] != op2){
                if(tops[i] == op2){
                    mv1++;
                }else{
                    pos = 0;
                    return -1;
                }
            }
            if(tops[i] !=op2){
                if(bottoms[i] == op2){
                    mv2++;
                }else{
                    pos = 0;
                    return -1;
                }
            }
        }

        return min(mv1, mv2);
    }
};