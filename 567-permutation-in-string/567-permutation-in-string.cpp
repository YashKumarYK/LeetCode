class Solution {
public:
    bool check_count(vector<int> count1, vector<int> count2){
        for(int i =0; i<count1.size(); i++){
            if( count1[i] != count2[i])
                return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        if(s1.length()> s2.length()) return false;
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(int i=0; i<s1.length(); i++){
            count1[s1[i]-'a']++;
        }
        
        int i =0;
        for( i=0; i<s1.length(); i++){
            count2[s2[i]-'a']++;
        }
        
        if( check_count(count1, count2)){
            return 1;
        }
        
        for( i = s1.length(); i<s2.length(); i++){
            count2[s2[i-s1.length()] -'a']--;
            count2[s2[i]-'a']++;
            
            if( check_count(count1, count2)){
            return 1;
            }
        }
        
        return 0;
    }
};