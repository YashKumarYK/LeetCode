class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort( s.begin(), s.end());
        
        for(int i=0; i<31;++i){
            string s1 = to_string( (int)pow(2,i));
            sort( s1.begin(), s1.end());            
            if( s1==s) return true;
        }
        return false;
    }
};