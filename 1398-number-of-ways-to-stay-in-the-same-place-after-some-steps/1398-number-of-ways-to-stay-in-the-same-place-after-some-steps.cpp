class Solution {
public:
    int m = 1e9+7;
    long long solve(int steps, int n, int ind, vector<vector<long long>> &dp){
        if(ind==n || ind<0) return 0;
        if(steps==0){
            if(ind==0) return 1;
            else return 0;
        }
        if(dp[ind][steps]!= -1) return dp[ind][steps]%m;
        long long stay = solve(steps-1, n, ind, dp);
        long long left = solve(steps-1, n, ind-1, dp);
        long long right = solve(steps-1, n, ind+1, dp);
        return dp[ind][steps] = (stay%m+ left%m+ right%m)%m;
        
    }
    int numWays(int steps, int arrLen) {
        arrLen = min(arrLen, steps/2+1);
        vector<vector<long long>> dp(arrLen+1, vector<long long> (steps+1, -1));
        return solve(steps, arrLen, 0, dp);
    }
}; 