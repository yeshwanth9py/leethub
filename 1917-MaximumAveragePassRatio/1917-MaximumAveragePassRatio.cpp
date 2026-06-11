// Last updated: 6/11/2026, 11:25:52 AM
struct node{
    int num;
    int den;
    // double frac;
    double incr;
};

struct Compare{
    bool operator()(node a, node b){
        return a.incr < b.incr;
    }
};

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int ex) {
        int n = classes.size();
        priority_queue<node, vector<node>, Compare> pq;
        for(auto cls: classes){
            int a = cls[0];
            int b = cls[1];
            double prev = a/(1.0*b);
            double nxt = (a+1)/(1.0*(b+1));
            double incr = nxt-prev; 

            pq.push({a, b, incr});
        }

        while(ex--){
            auto tel = pq.top(); pq.pop();
            int a = tel.num;
            int b = tel.den;
            // cout<<a<<" "<<b<<endl;
            a += 1;
            b += 1;
            double prev = a/(1.0*b);
            double nxt = (a+1)/(1.0*(b+1));
            double incr = nxt-prev; 
            pq.push({a, b, incr});
        }

        double avg = 0;
        while(!pq.empty()){
            auto tel = pq.top(); pq.pop();
            avg += tel.num/(1.0*tel.den);
        }

        avg = avg/n;

        return avg;

    }
};