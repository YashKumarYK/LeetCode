class Solution {
public:
    void solve(int ind, int n, int k, vector<int> &p, vector<vector<int>> & ans){
        if(k==0){
            ans.push_back(p);
            return;
        }
        if(ind ==n+1) return;

        solve(ind+1, n, k, p ,ans );
        p.push_back(ind);
        solve(ind+1, n, k-1, p, ans);
        p.pop_back();
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> p;
        vector<vector<int>> ans;
        solve(1, n, k, p, ans);
        return ans; 
    }
};