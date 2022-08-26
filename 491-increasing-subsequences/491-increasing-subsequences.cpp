class Solution {
public:
    void solve( vector<int>& nums, set<vector<int>> &ans, vector<int> v, int ind, int prev){
        
        if( ind == nums.size()){
            if(v.size()>=2)
                ans.insert(v);
            return;
        }
        
        solve( nums, ans, v, ind+1, prev);
        if( prev <= nums[ind]){
            v.push_back(nums[ind]);
            solve( nums, ans, v, ind+1, nums[ind]);
            v.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        set<vector<int>> s;
        solve( nums, s, v, 0, -1000);
        for( auto &i: s){
            ans.push_back(i);
        }
        return ans;
    }
};