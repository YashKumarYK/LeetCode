class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int diff=INT_MAX;
        for(int i=0; i<nums.size(); i++){
            
            if( abs(diff)>abs(nums[i])){
                diff = nums[i];
            }
            
            if(abs(diff) ==abs(nums[i]))
                diff= max(diff, nums[i]);
        }
        
        return diff;
    }
};