class Solution {
public:
    
    void solve( string s, int left, int right, vector<string> &ans, int n ){
        if( s.size()== n){
            ans.push_back(s);
            return;
        }
        if( left>0){
            solve( s+"(", left-1, right,ans, n);
           
        }
        if(right>left){
            solve( s+")", left, right-1, ans, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        string s ="(";
        vector<string> ans;
        solve( s, n-1, n, ans, 2*n);
        return ans;
    }
};