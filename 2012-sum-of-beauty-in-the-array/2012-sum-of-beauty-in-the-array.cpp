class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        bool first = true;
        int score=0;
        vector<vector<int>> v(nums.size(), vector<int> (2,0));
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            v[i][0]= maxi;
            if( maxi < nums[i]){
                maxi = nums[i];
            }
            
        }
        for( int i= nums.size()-1; i>=0; i--){
            v[i][1] = mini;
            if( mini > nums[i]){
                mini = nums[i];
            }
            
        }
        int count =0;
        for( int i=1; i<nums.size()-1; i++){
            if( nums[i]>v[i][0] && nums[i]<v[i][1]){
                count+=2;
            }
            else if(nums[i]>nums[i-1]&& nums[i]<nums[i+1]){
                count++;
            }
        }
        return count;
    }
};