RECURSION + MEMOIZATION
​
```
int solve( string &s , int n, int i, vector<int> &dp){
if( i == n) return 1;
if( s[i]=='0') return 0;
if( dp[i]!= -1) return dp[i];
if( i < n-1 && (s[i]=='1'|| (s[i]=='2'&& s[i+1]<'7')))
return dp[i] = solve( s, n,i+2, dp) +solve( s, n, i+1, dp);
else
return dp[i] = solve( s, n, i+1, dp);
}
```
​
DP- TABULATION
```
int numDecodings(string s){
int n = s.size();
vector<int> dp( n+1);
dp[n]=1;
for( int i= n-1; i>=0; --i){
if( s[i]=='0') dp[i]=0;
else if( i < n-1 && (s[i]=='1'|| (s[i]=='2'&& s[i+1]<'7')))
dp[i] = dp[i+2] +dp[i+1];
​
else
dp[i] = dp[i+1];
}
return dp[0];
}
```