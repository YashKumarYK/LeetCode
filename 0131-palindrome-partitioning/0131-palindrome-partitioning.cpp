class Solution {
public:
    bool ispal(string &s){
        int i=0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i]!= s[j]) return false;
            i++, j--;
        }
        return true;
    }
    void solve(string &s, int ind, vector<string> pal, vector<vector<string>> &ans){
        if(ind == s.size()) {
            ans.push_back(pal);
            return;
        }

        string s1;
        for(int i=ind; i<s.size(); i++){
            s1.push_back(s[i]);
            if(ispal(s1)){
                pal.push_back(s1);
                solve(s, i+1, pal, ans);
                pal.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pal;
        solve(s, 0, pal,ans);
        return ans;   
    }
};