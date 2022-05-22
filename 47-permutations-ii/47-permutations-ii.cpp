class Solution {
public:
    void solve( vector<int> nums, int index, set<vector<int>> &ans){
        if( index >= nums.size()){
            ans.insert( nums);
        }
        
        for( int j=index; j<nums.size(); j++){
            swap(nums[j], nums[index]);
            solve(nums, index+1, ans);
            
            //backtracking
            swap(nums[j], nums[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int index =0;
        vector<vector<int>> ans;
        set<vector<int>> s;
        solve(nums, index,s);
        for (auto i: s){
            ans.push_back(i);
        }
        return ans;
    }
};