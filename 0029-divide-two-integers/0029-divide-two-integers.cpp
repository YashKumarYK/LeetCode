class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = false;
        long long a = (long long )dividend, b = divisor;
         if (a == INT_MIN and b == -1) return INT_MAX;
        if (a == INT_MIN and b == 1) return INT_MIN;
        if(a<0){
            neg = !neg;
            a = abs(a);
        } 
        if(b<0){
            neg = !neg;
            b = abs(b);
        } 
        long long ans =0;
        long long quot=0;
        for( int i=31;i>=0;i--){
            if(quot +(b<<i)<=a){
                quot += (b<<i);
                ans += (1<<i);
            }
        }
        // if(ans>INT_MAX && !neg) return INT_MAX;
        return neg?-ans:ans;
    }
};