class Solution {
public:
    int longestPalindrome(vector<string>& words){
        unordered_map<string, int> mp;
        int count =0;
        for( auto i: words){
            string s;
            s.push_back(i[1]), s.push_back(i[0]);
            
            if( mp.find(s)!= mp.end()){
                count+=4;
                mp[s]--;
                if( mp[s]==0){
                    mp.erase(s);
                }
            }
            else{
                mp[i]++;
            }
            
        }
        for( auto i: mp){
            if( i.first[0]==i.first[1]){
                count+=2;
                break;
            }
        }
        return count;    
            
    }
};