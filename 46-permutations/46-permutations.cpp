class Solution {
public:
    void solve( vector<int> nums, int index, vector<vector<int>> &ans){
        if( index >= nums.size()){
            ans.push_back( nums);
        }
        
        for( int j=index; j<nums.size(); j++){
            swap(nums[j], nums[index]);
            solve(nums, index+1, ans);
            
            //backtracking
            swap(nums[j], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int index =0;
        vector<vector<int>> ans;
        solve(nums, index,ans);
        return ans;
    }
};