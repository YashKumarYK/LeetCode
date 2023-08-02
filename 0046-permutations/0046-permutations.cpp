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

// [2,3,6]
// [1,4,3]
// [24,3,27,54,9,90,30,60,20,100]
// [14,70,35,7,56,8,48,16,32,64]