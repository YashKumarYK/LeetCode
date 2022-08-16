class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for( int i=0; i<s.size(); ++i){
            mp[s[i]]++;
        }
        vector<pair<int, char>> v;
        for( auto i: mp){
            v.push_back({i.second, i.first});
        }
        sort( v.begin(), v.end(), greater<> ());
        string s1="";
        for( auto i: v){
            for( int j=0; j<i.first; j++){
                s1+= i.second;
            }
        }
        return s1;
    }
};