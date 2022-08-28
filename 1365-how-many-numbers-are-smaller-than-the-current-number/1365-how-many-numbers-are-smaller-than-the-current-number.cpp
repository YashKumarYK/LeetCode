class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v(nums.begin(), nums.end());
        
        sort( v.begin(), v.end());
        
        for( int i=0; i<nums.size(); ++i){
            int ind = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            
            nums[i]= ind;
        }
        return nums;
    }
};