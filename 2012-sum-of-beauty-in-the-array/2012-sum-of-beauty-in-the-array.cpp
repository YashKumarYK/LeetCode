class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {

        vector<int> v1( nums.size());
        vector<int> v2( nums.size());
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            v1[i]= maxi;
            if( maxi < nums[i]){
                maxi = nums[i];
            }
            v2[n-i-1]= mini;
            if( mini > nums[n-i-1]){
                mini = nums[n-i-1];
            }
        }
        int count =0;
        for( int i=1; i<nums.size()-1; i++){
            if( nums[i]>v1[i] && nums[i]<v2[i]){
                count+=2;
            }
            else if(nums[i]>nums[i-1]&& nums[i]<nums[i+1]){
                count++;
            }
        }
        return count;
    }
};