class Solution {
public:
    int m = 1e9 +7;
    
    int solve( int n, int k , int target, vector<vector<int>> &dp){
        if(n == 0 && target != 0)return 0;
        if(n == 0 && target == 0)return 1;
        if(target < 0)return 0;
        if(dp[n][target]!= -1) return dp[n][target]%m;
        long long count =0;
        for(int i=1; i<=k; i++){
            count += solve(n-1, k, target - i, dp);
            count = count%m;
        }
        return dp[n][target] = count;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int> (target+1,-1));
        return solve(n,k,target, dp);
    }
};