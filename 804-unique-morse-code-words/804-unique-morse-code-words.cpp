class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v(26);
        v= {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> set;
        for( auto word: words){
            string s ="";
            for( int i=0; i<word.size(); i++){
                s += v[word[i]-'a'];
            }
            set.insert(s);
        }
        return set.size();
    }
};