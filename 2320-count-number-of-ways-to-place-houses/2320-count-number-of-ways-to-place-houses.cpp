class Solution {
public:
    int m = 1e9+7;
    int solve( int n, int dp[]){
        if( n==1) return 2;
        if( n==2) return 3;
        if( dp[n] !=-1) return dp[n]%m;
        return dp[n]=(solve(n-1, dp)%m+ solve(n-2, dp)%m)%m;
    }
    int countHousePlacements(int n) {
        int dp[n+1];
        memset(dp, -1, sizeof(dp));
        long long ans = solve(n, dp)%m;
        ans = ((ans%m)*(ans%m))%m;
        return ans;
      
    }
};