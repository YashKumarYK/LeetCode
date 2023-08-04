class Solution {
public: 
    unordered_map<string, int> mp;
    vector<int> dp;
    bool solve( string s, vector<string> &wd, int ind){
        if(ind==s.size()) return true;
        if(dp[ind]!= -1) return dp[ind];
        string st;
        bool res = false;
        for(int i=ind; i<s.size(); i++){
            st.push_back(s[i]);
            if(mp.count(st)){
                if(solve(s, wd, i+1))  return dp[ind] = true;
            }
        }
        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wd) {
        for( auto i: wd) mp[i]++;
        dp.resize(s.size()+1, -1);
        return solve(s, wd, 0);
    }
};