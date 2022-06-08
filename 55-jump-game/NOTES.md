**Dynamic Programming**
```
vector<bool> dp(n+1);
dp[0]=true;
for(int i=1; i<n; i++){
for( int j = i-1 ; j>=0; j--){
if(dp[j] && j+nums[j]>=i){
dp[i]= true;
break;
}
}
}
return dp[n-1];
```
​
**Greedy**
****