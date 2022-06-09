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