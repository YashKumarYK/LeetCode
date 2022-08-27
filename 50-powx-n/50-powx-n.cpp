class Solution {
public:
    
    double solve( double x, int n){
        if( n==0){
            return 1.;
        }
        if( n==1) return x;
        double power = solve( x, n/2);
        if( n%2==0){
            return  power*power;
        }
        else{
            return x* power*power;
        }
    }
    double myPow(double x, int n) {
        if( n<0)
            x = double(1./x);
        
        return solve( x, abs(n));
    }
};