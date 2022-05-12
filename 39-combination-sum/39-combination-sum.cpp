class Solution {
public:
    void solve(vector<int>& candidates, int target, int index, vector<int> output,vector<vector<int>> &ans){
        if( target ==0){
            ans.push_back( output);
            return;
        }
        if( target <0) return;
        if(index==candidates.size()) return;
        
        //exclude
        solve(candidates, target, index+1, output, ans);
        
        //include
        
        output.push_back(candidates[index]);
        
        solve(candidates, target- candidates[index], index, output, ans);
        
        //backtracking
        output.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index;
        vector<vector<int>> ans;
        vector<int> output;
        solve(candidates,target, index, output, ans);
        return ans;
    }
};