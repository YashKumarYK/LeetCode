class Solution {
public:
//     bool solve( vector<int> & nums, int index, int n, vector<int> &dp){
//         if( index >= n-1) return true;
//         if( nums[index] == 0 ) return false;
        
//         if( dp[index] !=-1) return dp[index];
        
           
//         bool flag = false;
//         for( int i = index+1 ; i<=nums[index]+index; i++){
//             flag = flag || solve(nums, i, n, dp);
//         }
//         return dp[index]=flag;
//     }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n+1,-1);
        if(nums.size()==1)
            return true;
        // return solve( nums, 0, n, dp);
        
        //DP approach
        // vector<bool> dp(n+1);
        // dp[0]=true;
        // for(int i=1; i<n; i++){
        //     for( int j = i-1 ; j>=0; j--){
        //             if(dp[j] && j+nums[j]>=i){
        //                 dp[i]= true;
        //                 break;
        //             }
        //     }
        // }
        // return dp[n-1];
        
        ///greedy
        int reach =0;
        for( int i=0; i<n; i++){
            if (reach<i) return false;
            reach = max(reach, i+nums[i]);
        }
        return true;
    }
};