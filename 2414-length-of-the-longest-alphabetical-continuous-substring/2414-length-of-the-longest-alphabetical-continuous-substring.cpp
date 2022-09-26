class Solution {
public:
    int longestContinuousSubstring(string s) {
        int i=0, j=1, len= 1;
        char prev = s[i];
        while(j<s.size()){
            if( s[j]== prev+1){ 
                prev = s[j];
            }
            else{
                len = max( len , j-i);
                i=j;
                prev= s[j];
            }
            j++;
        }
        len = max(len, j-i);
        return len;
    }
};