// Last updated: 6/11/2026, 11:24:17 AM
class Robot {
public:
    int rx;
    int lx;
    int ty;
    int by;
    int cx;
    int cy;
    vector<string> direct = {"North", "East", "South", "West"};
    int dir;
    int peri;
    Robot(int w, int h) {
        ty = h-1;
        by = 0;
        rx = w-1;
        lx = 0;
        cx = cy = 0;
        dir = 1;
        peri = 2*(w-1) + 2*(h-1);
    }
    void step(int num) {
        if(num>=peri){
            num = num%peri;
            if(cx == 0 && cy == 0 && num == 0) dir = 2;
        }
        while(num>0){
            if(dir == 0){
                int desty = cy+num;
                num = 0;
                if(desty>ty){
                    num = desty-ty;
                    desty = ty;
                    dir = (dir-1+4)%4;
                }
                cy = desty;
            }else if(dir == 1){
                int destx = cx+num;
                num = 0;
                if(destx>rx){
                    num = destx-rx;
                    destx = rx;
                    dir = (dir-1+4)%4;
                }
                cx = destx;
            }else if(dir == 2){
                int desty = cy-num;
                num = 0;
                if(desty<0){
                    num = -desty;
                    desty = 0;
                    dir = (dir-1+4)%4;
                }
                cy = desty;
            }else{
                int destx = cx-num;
                num = 0;
                if(destx<0){
                    num = -destx;
                    destx = 0;
                    dir = (dir-1+4)%4;
                }
                cx = destx;
            }
        }
    }
    
    vector<int> getPos() {
        return {cx, cy};
    }
    
    string getDir() {
        return direct[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */