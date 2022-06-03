class Solution {
public:
    int myAtoi(string s) {
        
        int n = s.length();
        int index =0;
        int sign =1;
        int result =0;
        int m = 1000000007;
        //removing leading spaces
        while( index<n  && s[index] ==' '){
            index++;
        }
        
        //checking the sign
        if( index<n && s[index] == '-'){
            sign = -1;
            index++;
        }
        else if( index<n && s[index]== '+'){
            sign = 1;
            index++;
        }
        
        //traversing the string
        while( index<n && isdigit(s[index])){
            int digit = s[index]- '0';
            if( result> INT_MAX/10 || result == INT_MAX/10 && digit > INT_MAX%10){
                if( sign ==1){
                    return INT_MAX;
                }
                else
                    return INT_MIN;
            }
            result = ((result)*10 + digit);
            index++;
        }
        return sign*result;
    }
};