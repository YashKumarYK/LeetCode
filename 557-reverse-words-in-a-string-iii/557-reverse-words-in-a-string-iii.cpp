class Solution {
public:
    void reverse( string &s, int st, int e){
        while(st<=e){
            swap(s[e], s[st]);
            st++;
            e--;
        }
    }
    string reverseWords(string s) {
        int st=0;
        int e=st+1;
        while( e<s.size()){
            if(( s[e-1]!= ' ' &&  s[e]== ' ' ) || e== s.size()){
                reverse(s, st,e-1);
            }
            if( s[e-1]==' ' && s[e] !=' '){
                st= e;
            }
            e++;
        }
        reverse(s, st, e-1);
        return s;
    }
};