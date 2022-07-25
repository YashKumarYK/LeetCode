class Solution {
public:
    int dp[20];
    int solve( int n ){
        if( n==0) return 1;
        if( n==1) return 1;
        if( n==2) return 2;
        if( dp[n]!= -1) return dp[n];
        int count=0;
        for(int k=1; k<=n; k++){
            count+= solve(k-1)* solve(n-k);
        }
        return dp[n] = count;
        
    }
    int numTrees(int n) {
        //catalans number
        memset(dp, -1, sizeof(dp));
        return solve( n);
    }
};