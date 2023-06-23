class Solution {
public:
    
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<unordered_map<int,int>> dp(n+1);
        for(int i= 1; i<n; i++){
            for(int j = 0; j<i; j++){
                int cnt =1;
                int diff = nums[i]-nums[j];
                
                //checking if the sequence of same difference exists or not
                if(dp[j].find(diff)!= dp[j].end()){
                    cnt = dp[j][diff];
                }
                dp[i][diff] =  1+ cnt;
                ans = max( ans, dp[i][diff]);
            }
        }
        return ans;
    }
};