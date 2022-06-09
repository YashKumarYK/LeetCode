**RECURSION**
```
int solve(int target, int s){
if( target==0) return 0;
if( s<=0) return INT_MAX;
int p = s*s;
if( p<=target){
return min(1+solve(target-p,s), solve(target,s-1));
}
else{
return solve(target, s-1);
}
}
int numSquares(int n) {
if( n<4) return n;
int s= sqrt(n);
return solve( n,s);
}
```
​
**RECURSION WITH MEMOIZATION**
```
int solve(int target, int s,vector<vector<int>> &dp){
if( target==0) return 0;
if( s<=0) return INT_MAX;
if( dp[s][target] !=-1) return dp[s][target];
int p = s*s;
if( p<=target){
return dp[s][target]=min(1+solve(target-p,s,dp), solve(target,s-1,dp));
}
else{
return dp[s][target]= solve(target, s-1,dp);
}
}
int numSquares(int n) {
if( n<4) return n;
int s= sqrt(n);
vector<vector<int>> dp(s+1, vector<int> (n+1,-1));
return solve( n,s, dp);
}
```