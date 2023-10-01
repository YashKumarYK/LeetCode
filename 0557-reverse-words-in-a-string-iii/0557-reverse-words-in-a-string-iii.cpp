class Solution {
public:
    void Rreverse( string &s, int st, int e){
        while(st<=e){
            swap(s[e], s[st]);
            st++;
            e--;
        }
    }
    string reverseWords(string s) {
        int k=0;
        for( int i =0; i<=s.length(); i++){
            if( s[i]==' ' || i == s.length()){
                reverse(s.begin()+k, s.begin()+i);
                k= i+1;
            }
            
        }
        return s;
    }
};