class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0;
        int ans =0;
        int maxi = *max_element(nums.begin(), nums.end());
        
        while( i<nums.size()){
            int j=i;
            while( j<nums.size() && nums[i]==nums[j]){
                j++;
            }
            int len = j-i;
            if( nums[i]==maxi)
                ans = max( ans, len);
            i=j;
            
        }
        return ans;
    }
};