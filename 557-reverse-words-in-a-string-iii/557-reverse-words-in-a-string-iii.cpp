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
        
        //first solution 
        
        // int st=0;
        // int e=st+1;
        // while( e<s.size()){
        //     if(( s[e-1]!= ' ' &&  s[e]== ' ' ) || e== s.size()){
        //         Rreverse(s, st,e-1);
        //     }
        //     if( s[e-1]==' ' && s[e] !=' '){
        //         st= e;
        //     }
        //     e++;
        // }
        // reverse(s, st, e-1);
        // return s;
        
        //second solution
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