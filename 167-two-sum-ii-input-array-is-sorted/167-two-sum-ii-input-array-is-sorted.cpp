class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        int s=0;
        int e = nums.size()-1;
        while( s<=e){
            if(nums[s]+nums[e]==k) return {s+1,e+1};
            else if( nums[s]+nums[e]>k) e--;
            else s++;
        }
        return {s+1,e+1};
    }
};