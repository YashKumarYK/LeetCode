class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int diff=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if( diff>abs(nums[i])){
                diff = abs(nums[i]);
                maxi = nums[i];
            }
            if(diff ==abs(nums[i]))
                maxi= max(maxi, nums[i]);
        }
        return maxi;
    }
};