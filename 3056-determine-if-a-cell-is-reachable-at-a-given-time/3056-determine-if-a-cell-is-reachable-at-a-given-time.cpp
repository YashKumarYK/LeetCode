class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx && sy==fy){
            if(t==1) return false;
            else return true;
        }
        int a = abs(sx-fx);
        int b = abs(sy-fy);
        if(a<=t && b<=t) return true;
        return a+b<=t;
    }
};