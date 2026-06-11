// Last updated: 6/11/2026, 11:18:02 AM
struct Unionfind{
    vector<long long> par;
    vector<long long> sz;
    long long noc;
    
    Unionfind(long long n){
        par.resize(n, 0);
        sz.resize(n, 1);
        noc = n;
        
        for(long long i=0; i<n; i++){
            par[i] = i;
        }
    }
    
    long long find(long long u){
        if(u == par[u]) return u;
        return par[u] = find(par[u]);
    }
    
    bool merge(long long u, long long v){
        u = find(u);
        v = find(v);
        
        if(u == v) return 0;
        if(sz[v]>=sz[u]) swap(u, v);
        
        sz[u] += sz[v];
        noc--;
        par[v] = u;
        return 1;
    }
};

class Solution {
public:
    bool canReachCorner(long long xc, long long yc, vector<vector<int>>& arr) {
        long long n = arr.size();
        long long top = n;
        long long right = n+1;
        long long bot = n+2;
        long long left = n+3;

        Unionfind uf(n+4);

        for(long long i=0; i<n; i++){
            long long x1 = arr[i][0];
            long long y1 = arr[i][1];
            long long r1 = arr[i][2];

            if(x1*x1 + y1*y1 <= r1*r1) return 0;
            if((x1-xc)*(x1-xc) + (y1-yc)*(y1-yc) <= r1*r1) return 0;

            long long leftp = max(0LL, min(yc, y1));
            
            if((x1*x1)+((y1-leftp)*(y1-leftp)) <= r1*r1){
                uf.merge(i, n+3);
            }

            long long topp = max(0LL, min(xc, x1));
            if(((x1-topp)*(x1-topp))+((y1-yc)*(y1-yc)) <= r1*r1){
                uf.merge(i, n);
            }

            long long rightp = max(0LL, min(y1, yc));
            if(((x1-xc)*(x1-xc)) + ((y1-rightp)*(y1-rightp)) <= r1*r1){
                uf.merge(i, n+1);
            }

            long long downp = max(0LL, min(x1, xc));
            if(((x1-downp)*(x1-downp)) + (y1*y1) <= (r1*r1)){
                uf.merge(i, n+2);
            }

            for(long long j=i+1; j<n; j++){
                long long x2 = arr[j][0];
                long long y2 = arr[j][1];
                long long r2 = arr[j][2];

                if(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) <= (r1+r2)*(r1+r2)){
                    long long px = (x2*r1 + x1*r2);
                    long long py = (y2*r1 + y1*r2);

                    if(px>0 && px<((r1+r2)*xc) && py>0 && py<((r1+r2)*yc)){
                        uf.merge(i, j);
                    }
                }
            }
        }


        if(uf.find(left) == uf.find(bot) || uf.find(left) == uf.find(right) || uf.find(top) == uf.find(right) || uf.find(top) == uf.find(bot)) return 0;
        return 1;


    }
};



