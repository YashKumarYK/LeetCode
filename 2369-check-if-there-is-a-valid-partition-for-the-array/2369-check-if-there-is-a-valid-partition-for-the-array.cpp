class Solution {
public:
    int dp[100001];
    bool condition( vector<int> & nums, int i, int j){
        if( j==i+2 && nums[i]==nums[i+1] && nums[i]==nums[j]) return true;
        else if(j==i+1 && nums[i]==nums[j]) return true;
        else if( j==i+2 && nums[i]+1 ==nums[i+1] && nums[i+1]+1 == nums[j]) return true;
        else 
            return false;        
    }
    
    bool solve( vector<int> &nums, int ind){
        if( ind == nums.size()) return true;
        if( dp[ind] != -1){
            return dp[ind];
        }
        int  n = nums.size();
        int mini= min( {ind+2, n-1});
        for( int k = ind; k<=mini; k++){
            if( k!=ind && condition( nums, ind, k)){
                if( solve(nums, k+1)) return dp[ind] =true;
            }
        }
        return dp[ind] = false;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve( nums,0);
    }
};