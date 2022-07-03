}
}
int wiggleMaxLength(vector<int>& nums) {
vector<vector<int>> dp1( nums.size(), vector<int> (2, -1));
return 1+ max( solve( 1,nums, 0, dp1), solve( 1, nums, 1, dp1));
}
```
​
***Greedy approach ***
```
int wiggleMaxLength(vector<int>& nums) {
// vector<vector<int>> dp1( nums.size(), vector<int> (2, -1));
// return 1+ max( solve( 1,nums, 0, dp1), solve( 1, nums, 1, dp1));
if( nums.size()< 2) return nums.size();
int prediff = nums[1]-nums[0];
int count = prediff!=0?1:0;
for(int i=2; i<nums.size(); i++){
int diff = nums[i]- nums[i-1];
if((diff>0 && prediff<=0) || (diff<0 && prediff>=0)){
count++;
prediff = diff;
}
}
return count+1;
}
```