class Solution {
public:
    
    vector<int> count( string b){
        vector<int> mp(26,0);
        for( auto i: b){
            mp[i-'a']++;
        }
        return mp;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> bmax(26, 0);
        for( auto b : words2){
            vector<int> mp2 = count( b);
            for( int i=0; i<26; i++){
                bmax[i]= max( bmax[i], mp2[i]);
            }
        }
        vector<string> ans;
        for( auto a: words1){
            bool flag = true;
            vector<int> mp2 = count(a);
            for( int i =0; i<26; i++){
                if( bmax[i]> mp2[i]){
                    flag = false;
                    break;
                }
            }
            if( flag){
                ans.push_back( a);
            }
        }
        return ans;
    }
};