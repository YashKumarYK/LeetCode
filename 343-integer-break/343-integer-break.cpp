class Solution {
public:
    
    int solve( int i , vector<int> &num, int sum, vector<vector<int>> &dp){
        if( i==num.size() || sum==0){
            return 1;
        }
        if( dp[i][sum] !=-1) return dp[i][sum];
        if( num[i]<=sum){
            return dp[i][sum] = max( num[i]* solve( i, num, sum-num[i], dp), solve( i+1, num, sum, dp));
        }
        else{
            return dp[i][sum] = solve(i+1, num, sum, dp);
        }
    }
    int integerBreak(int n) {
        vector<int> num(n-1);
        for(int i=0; i<n-1; i++){
            num[i]= i+1;
        }
        vector<vector<int>> dp( n-1,vector<int> (n+1,-1));
        return solve(0, num, n, dp);
    }
};