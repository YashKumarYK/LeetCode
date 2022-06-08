**Recursion Code**
```
int solve( vector<int> &nums, int n, int index){
if( index>=n-1){
return 0;
}
if( nums[index]==0) return n;
int mini = n+1;
for(int i=index+1; i<= min(n-1, index+nums[index]);i++){
mini= min(mini, 1+ solve(nums, n, i));
}
return mini;
}
int jump(vector<int>& nums) {
int n = nums.size();
if( n ==1) return 0;
return solve( nums, n,0);
}
```
​
**Recursion+ memoization**
​