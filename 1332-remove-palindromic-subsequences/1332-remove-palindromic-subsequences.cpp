class Solution {
public:
    bool ispalindrome(string s){
        int st =0;
        int e= s.size()-1;
        while( st<e){
            if(s[st]!=s[e]){
                return false;
            } 
            st++;
            e--;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if( ispalindrome(s)) return 1;
        return 2;
    }
};