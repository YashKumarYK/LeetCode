class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> count(26,0);
        
        for(char i: magazine){
            count[i-'a']++;
        }
        
        for( char i: ransomNote){
            if(count[i-'a'] == 0) 
                return false;
            else count[i-'a']--;
        }
        return true;
    }
};