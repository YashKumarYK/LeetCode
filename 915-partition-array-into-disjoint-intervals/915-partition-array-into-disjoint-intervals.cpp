class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n), right(n);
        int maxi = nums[0];
        for( int i=0; i<n; i++){
            left[i]= maxi;
            maxi = max( maxi, nums[i]);
        }
        int mini= nums[n-1];
        for( int i= n-1; i>=0; --i){
            right[i]= mini;
            mini = min( mini, nums[i]);
        }
        int count =1;
        for( int i=0; i<nums.size()-1; i++){
            if( left[i] > right[i]){
                count++;
            }
            else break;
        }
        return count;
    }
};