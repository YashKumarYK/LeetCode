class Solution {
public:
    void solve(vector<int> nums, vector<int> output, vector<vector<int>> &ans, int index){
        ans.push_back(output);        
        for( int i= index; i<nums.size(); i++){
            if (i>index && nums[i]==nums[i-1]) continue;
            output.push_back(nums[i]);
            
            solve(nums,output, ans, i+1);
            output.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        int index =0;
        sort(nums.begin(), nums.end());
        solve( nums, output, ans, index);
        return ans;
    }
};