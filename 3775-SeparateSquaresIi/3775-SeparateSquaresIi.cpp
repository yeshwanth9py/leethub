// Last updated: 6/11/2026, 11:16:02 AM
class Solution {

    struct Seg{
        vector<int> cover;
        vector<int> clen;
        vector<int> len;
        vector<int> w;

        Seg(int n, vector<int> &widths){
            cover.resize(4*n, 0);
            clen.resize(4*n, 0);
            len.resize(4*n, 0);
            w = widths;
            build(1, 0, n-1);
        }

        void build(int idx, int l, int r){
            if(l == r){
                len[idx] = w[l];
                return;
            }
            int mid = (l+r)/2;
            build(2*idx, l, mid);
            build(2*idx+1, mid+1, r);
            len[idx] = len[2*idx] + len[2*idx+1];
        }

        void update(int idx, int l, int r, int ql, int qr, int v){
            if(r < ql || qr < l) return;
            
            if(ql <= l && r <= qr){
                cover[idx] += v;
            }else{
                int mid = (l+r)/2;
                update(2*idx, l, mid, ql, qr, v);
                update(2*idx+1, mid+1, r, ql, qr, v);
            }

            if(cover[idx]>0){
                clen[idx] = len[idx];
            }else{
                if(l == r){
                    clen[idx] = 0;
                }else{
                    clen[idx] = clen[2*idx] + clen[2*idx+1];
                }
            }
        }
    };

public:
    double separateSquares(vector<vector<int>>& sqs) {
        vector<int> xcords;
        vector<vector<int>> events;
        map<int, int> mpx;
        
        for(auto el: sqs){
            int x = el[0];
            int y = el[1];
            int len = el[2];
            mpx[x] = 1;
            mpx[x+len] = 1;
            events.push_back({y, +1, x, x+len});
            events.push_back({y+len, -1, x, x+len});
        }

        int idx = 0;
        for(auto el: mpx){
            mpx[el.first] = idx;
            xcords.push_back(el.first);
            idx++;
        }

        vector<int> widths;
        long long total_width = 0;
        for(int i=0; i<idx-1; i++){
            int cw = abs(xcords[i]-xcords[i+1]);
            widths.push_back(cw);
            total_width += cw;
        }

        int til = idx-1;
        Seg sg(til, widths);

        sort(events.begin(), events.end());

        double totarea = 0;
        // Using double for history prevents overflow during area checks
        vector<vector<double>> history; 

        for(int i=0; i<events.size()-1; i++){
            auto el = events[i];
            int nexty = events[i+1][0];
            int y = el[0];
            int typ = el[1];
            int xl = el[2];
            int xr = el[3];
            
            sg.update(1, 0, til-1, mpx[xl], mpx[xr]-1, typ);
            
            int unionx = sg.clen[1];

            if(nexty > y){
                history.push_back({(double)y, (double)unionx, (double)(nexty-y)});
                totarea += (double)unionx * (nexty-y);
            }
        }

        double target = totarea / 2.0;
        double cura = 0;
        
        for(auto el: history){
            double y = el[0];
            double ux = el[1];
            double uy = el[2];
            
            double sarea = ux * uy;
            
            // Check if this slice crosses the target
            if(cura + sarea >= target){
                double need = target - cura;
                return y + (need / ux);
            }
            cura += sarea;
        }

        return 0.0;
    }
};