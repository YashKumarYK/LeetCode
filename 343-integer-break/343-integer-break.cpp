class Solution {
public:
    int integerBreak(int n) {
        int ans =1;
        if( n<4) return n-1;
        while( n>4){
            ans*= 3;
            n-=3;
        }
        return n*ans;
    }
};