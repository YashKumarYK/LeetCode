class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i=0;
        int j =0;
        unordered_map<int,int> mp;
        int maxLen = 0;
        int maxOccur =0;
        while(j<n){
            mp[s[j]]++;
            maxOccur = max(mp[s[j]], maxOccur);

            if((j-i+1)- maxOccur<=k ){
                maxLen  = max(maxLen, j-i+1);
            }
            if((j-i+1)- maxOccur>k){
                while((j-i+1)- maxOccur>k){
                    mp[s[i]]--;
                    if(mp[s[i]]==0) mp.erase(s[i]);
                    i++;
                }
                if((j-i+1)- maxOccur<=k){
                    maxLen  = max(maxLen, j-i+1);
                }
            }
            j++;
        }
        return maxLen;
    }
};