class Solution {
public:
    void solve( int index , int k, int n, vector<int> output, vector<vector<int>> &ans){
        if( n==0 && output.size()==k){
            ans.push_back(output);
            return;
        }
        
        for(int i= index; i<=9; i++){
            output.push_back(i);
            solve( i+1, k, n-i, output, ans);
            output.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;
        int index =1;
        solve(index, k, n, output, ans);
        return ans;
    }
};