class Solution {
public:
    string arr[10] = {"","", "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(string digit, int ind,string p, vector<string> &ans){
        if(ind==digit.size()){
            if(p.size()!=0)
                ans.push_back(p);
            return;
        }
        int idx = digit[ind]-'0';
        for(int i=0;i<arr[idx].size();i++){
            p.push_back(arr[idx][i]);
            solve(digit,ind+1, p, ans);
            p.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        string p;
        solve(digits, 0, p, ans);
        return ans;
    }
};