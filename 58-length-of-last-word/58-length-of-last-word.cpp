class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int e=n;
        for(int i=n-1; i>=0; i--){
            if( s[i] != ' '){
                e=i;
                break;
            }
        }
        int count=0;
        for( int i=e; i>=0; i--){
            if(s[i]==' ')
                break;
            count++;
        }
        return count;
    }
};