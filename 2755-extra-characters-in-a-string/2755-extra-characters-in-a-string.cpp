class Solution {
public:
    int solve(unordered_map<string, int> &mp, string &s, int ind, vector<int> &dp){
        if(ind== s.size()) return 0;

        if(dp[ind]!= -1) return dp[ind];

        int ans = 10000000;

        string s1;
        for(int i=ind; i<s.size(); i++){
            s1.push_back(s[i]);
            int nextcall = solve(mp, s, i+1, dp);
            if(mp.count(s1)){
                ans = min({ans ,nextcall,  (i-ind+1)+ nextcall});
            }else{
                ans = min((i-ind+1)+ nextcall, ans);
            }
        }
        return dp[ind] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string,int> mp;
        for( auto &words: dictionary){
            mp[words]++;
        }
        vector<int> dp(s.size()+1, -1);
        return solve(mp, s, 0, dp);
    }
};