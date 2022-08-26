class Solution {
public:
    long long smallestNumber(long long num) {
        int sign = num>=0?1:-1;
        if( num ==0) return 0;
        string s = to_string(num*sign);
        
        if(sign==1)
            sort(s.begin(), s.end());
        else{
            sort(s.begin(), s.end(), greater<>());
        }
        int i=0, j=0;
        while( j<s.size()  && s[j]=='0') j++;
        swap(s[i], s[j]);
        
        return stoll(s)*sign;
    }
};