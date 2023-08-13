class Solution {
public:
    bool condition(vector<int>  &nums, int i,int j){
        if(j-i+1==2){
            return nums[i]==nums[j];
        }
        if(j-i+1==3){
            return (nums[i]==nums[j]&&nums[j]==nums[i+1])||(nums[i]==nums[i+1]-1 && nums[i+1]+1==nums[j]);
        }
        return false;

    }
    // int solve( vector<int> & nums, int ind, int n){
    //     if(ind==n) return true;
        
    //     for(int i=ind+1; i<=min(ind+3, n-1); i++){
    //         if(condition(nums, ind, i)){
    //             if(solve(nums, i+1,n)) return true;
    //         }
    //     }
    //     return false;

    // }
    bool validPartition(vector<int>& nums) {
        // return solve(nums, 0, nums.size());
        int n =nums.size();
        vector<bool> dp(n+2, false);
        dp[n] = true;
        for(int i=n-1;i>=0;i--){
            for(int j = i+1; j<= min(i+3, n-1); j++){
                if( condition(nums, i, j)){
                    if(dp[j+1]) dp[i] = true;
                }
            }
            
        }
        return dp[0];
    }
};