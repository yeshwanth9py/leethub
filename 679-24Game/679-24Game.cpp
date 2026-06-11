// Last updated: 6/11/2026, 11:31:57 AM
class Solution {
public:
    char opers[4] = {'+', '-', '*', '/'};
    double ek_solve(double a, double b, int op){
        if(op == 0){
            return a+b;
        }else if(op == 1){
            return a-b;
        }else if(op == 2){
            return 1LL*a*b;
        }else{
            if(b == 0){
                return 1e9;
            }
            return a/(1.0*b);
        }
    }

    bool solve(vector<double> card){
        if(card.size()==1){
            return (abs(card[0]-24)<1e-3);
        }

        for(int i=0; i<card.size()-1; i++){
            //i and i+1
            for(int op = 0; op<4; op++){
                vector<double> temp = card;
                double val = ek_solve(temp[i], temp[i+1], op);
                temp.erase(temp.begin()+i+1);
                temp[i] = val;
                if(solve(temp)){
                    return 1;
                }
            }

        }

        return 0;
    }

    bool judgePoint24(vector<int>& cardsi) {
        vector<double> cards;
        for(int el: cardsi){
            cards.push_back(el);
        }
        sort(cards.begin(), cards.end());
        do{
            if(solve(cards)){
                return 1;
            }
        }while(next_permutation(cards.begin(), cards.end()));
        return 0;
    }
};