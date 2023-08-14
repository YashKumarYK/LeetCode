class Solution {
public:
    void solve(vector<int> &c, int t, vector<int> &el, vector<vector<int>> &ans, int ind){
        if(t==0){
            ans.push_back(el);
            return;
        }
        if(t<0 || ind>=c.size()) return;

        for(int i= ind; i<c.size(); i++){
            if(i>ind && c[i] == c[i-1]) continue;         
            
            el.push_back(c[i]);
            solve(c, t-c[i], el, ans, i+1);
            el.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<int> ele;
        vector<vector<int>> ans;
        sort(c.begin(), c.end());
        solve(c, target, ele, ans, 0);

        return ans;
    }
};