class Solution {
public:
    string largestPalindromic(string num) {
        unordered_map<char, int> mp;
        for(int i=0;i<num.size(); i++){
            mp[num[i]]++;
        }
        vector<pair<char, int>> v;
        for( auto i:mp){
            
            v.push_back({i.first, i.second});
        }
        if( v.size()==1 && v[0].first =='0') return "0";
        sort( v.begin(), v.end(), greater<> ());
        string s ="";
        char odd= 'a';
        for( auto i: v){
            if( odd =='a' && i.second%2!=0){
                odd= i.first;
            }
            for( int j=0; j<i.second/2;++j){
                if(i.first=='0' && s=="") continue;
                s+= i.first;
            }
        }
        string s1 = s;
        reverse(s1.begin(), s1.end());
        if( odd != 'a'){
            s+= odd;
        }
        return s+s1;
    }
};