class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> v(26, 0);
        for( auto ch: t){
            v[ch-'a']++;
        }
        for( auto i:v){
            cout<<i<<" ";
        }
        for(auto ch: s){
            v[ch-'a']--;
        }
        cout<<endl;
        for( auto i:v){
            cout<<i<<" ";
        }
        for(int i=0;i<26; i++){
            if( v[i]>=1) return i+'a';
        }
        return  -1;
    }
};