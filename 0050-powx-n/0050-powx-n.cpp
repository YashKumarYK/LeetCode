class Solution {
public:

    double solve( double x, int n){
        if(n==0) return 1.;
        if(n==1) return (double)x;
        double power = solve(x, n/2);
        if(n&1){
            return (double)power*power*x;
        }
        else return (double) power*power;
    }
    double myPow(double x, int n) {
        if(n<0){
            x = (double)1./x;
        }
        return solve(x, n);
    }
};