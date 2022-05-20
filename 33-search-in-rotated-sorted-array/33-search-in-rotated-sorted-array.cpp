class Solution {
public:
    int binary_search( vector<int> nums, int target, int s, int e){
        int mid = s+ (e-s)/2;
        while( s <= e){
            if (nums[mid] == target) return mid;
            else if( nums[mid] > target) e= mid -1;
            else{
                s= mid+1;
            }
            mid = s+ (e-s)/2;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s+ (e-s)/2;
        
        //find pivot
        while( s<e){
            if( nums[mid]>= nums[0]){
                s= mid+1;
            }
            else{
                e= mid;
            }
            mid = s+ (e-s)/2;
        }
        int pivot_index = s;
        int ans;
        if( nums[pivot_index] <= target && target <= nums[nums.size()-1]){
            ans = binary_search(nums, target, pivot_index, nums.size()-1);
            
        }
        else{
            ans = binary_search(nums, target, 0, pivot_index-1);
        }
        return ans;
    }
};