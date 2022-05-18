class Solution {
public:
    bool check_count(vector<int> count1, vector<int> count2){
        for(int i =0; i<count1.size(); i++){
            if( count1[i] != count2[i])
                return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.length()> s.length()) return ans;
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(int i=0; i<p.length(); i++){
            count1[p[i]-'a']++;
        }
        
        int i =0;
        for( i=0; i<p.length(); i++){
            count2[s[i]-'a']++;
        }
        
        if( check_count(count1, count2)){
            ans.push_back(0);
        }
        
        for( i = p.length(); i<s.length(); i++){
            count2[s[i-p.length()] -'a']--;
            count2[s[i]-'a']++;
            
            if( check_count(count1, count2)){
                ans.push_back( i- p.length()+1);
            }
        }
        
        return ans;
    }
};