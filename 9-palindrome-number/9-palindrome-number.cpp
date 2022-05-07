class Solution {
public:
    bool isPalindrome(int x) {
        long int ans=0;
        int y =x;
        if( x<0) return 0;
        while(x){
            int temp = x%10;
            ans = ans*10 + temp;
            x=x/10;
        }
        return ans ==y;
    }
};