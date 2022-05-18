class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = -1;
        unordered_map<char, int> mp;
        int i=0; int j=0;
        if( s.length() ==0) return 0;
        while(j<s.length()){
            mp[s[j]]++;
            
            if(mp.size() == j-i+1){
                length = max( length, j-i+1);
            }
            
            else if( mp.size()< j-i+1){
                while( mp.size() < j-i+1){
                    mp[s[i]]--;
                    if( mp[s[i]]==0)
                        mp.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return length;
        
    }
};