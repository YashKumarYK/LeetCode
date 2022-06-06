class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        int k = digit-'0';
        int f = -1; // variable for storing the last occurence
        for( int i=0;  i<n-1; i++){
            if( number[i]== digit){
                if( number[i+1]>number[i])
                    return number.substr(0,i) + number.substr(i+1);
                f=i;
            }
        }
        if(number[n-1] == digit){
            return number.substr(0, n-1);
        }
        
        return number.substr(0,f)+ number.substr(f+1);
        
    }
};