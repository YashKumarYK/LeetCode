class Solution {
public:
//     int dp[20];
//     int solve( int n ){
//         if( n==0) return 1;
//         if( n==1) return 1;
//         if( n==2) return 2;
//         if( dp[n]!= -1) return dp[n];
//         int count=0;
//         for(int k=1; k<=n; k++){
//             count+= solve(k-1)* solve(n-k);
//         }
//         return dp[n] = count;
        
//     }
    int tab( int n){
        vector<int> dp(n+1, 0);
        dp[0]=dp[1]=1;
        for(int i=2; i<=n; i++){
            for(int k=1; k<=i; k++){
                dp[i] += dp[k-1]* dp[i-k];
            }
        }
        return dp[n];
    }
    int numTrees(int n) {
        //catalans number
        // memset(dp, -1, sizeof(dp));
        return tab( n);
    }
};