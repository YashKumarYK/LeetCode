
class Solution {
public:
    
    bool solve( vector<int> &nums, int k, int ind, int s , int sum, vector<int> &vis){
        if( k==1) return  true;
        if( ind ==nums.size() || s> sum) return false;
        
        if( s == sum) return solve( nums , k-1, 0, 0, sum, vis);
    
        int pick =0;
        if( vis[ind]==0){
            vis[ind]=1;
            s= s+ nums[ind];
            int pick = solve( nums, k, ind+1, s, sum, vis);
            if( pick==1) return true;
            vis[ind]=0;
            s-= nums[ind];
        }
        
        int nopick = solve(nums, k, ind+1,s,  sum, vis);
        
        return nopick;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate( nums.begin(), nums.end(), 0);
        if( k> nums.size() || sum%k !=0) return false;
        int n =  nums.size();
        vector<int> vis( n, 0);
        sum = sum/k;
        sort( nums.begin(), nums.end(), greater<int> ());
        
        return solve( nums, k, 0, 0, sum, vis );
    }
};