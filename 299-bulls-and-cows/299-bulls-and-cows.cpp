class Solution {
public:
    string getHint(string s, string g) {
        int a =0;
        vector<int> v(10, 0);
        vector<int> v2(10,0);
        for( int i=0; i<s.size(); i++){
            if( s[i]== g[i]){
                a++;
            }
            v[s[i]-'0']++;
            v2[g[i]-'0']++;
        }
        
        int count =0;
        for( int i=0;i<=9; i++){
            count += min( v[i], v2[i]);
        }
        
        return to_string(a) +"A" + to_string(count-a) +"B";
    }
};