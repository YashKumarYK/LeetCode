class Solution {
public:
  vector<string> ans;

    void solve(string &s, int ind, string &sen, unordered_map<string, int> &mp){
        if(ind== s.size()){
            ans.push_back(sen);
            return ;
        }

        string s1;
        for(int i=ind; i<s.size(); ++i){
            s1.push_back(s[i]);
            if(mp.count(s1)){
                string old = sen;
                if(sen.size()!=0) sen+=" ";
                sen+= s1;
                (solve(s, i+1, sen, mp));
                sen = old;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string, int> mp;
        for(auto word:wordDict){
            mp[word]++;
        }
        string sen="";
        solve(s, 0, sen, mp);
        return ans;
    }
};