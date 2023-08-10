class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        /*have to check case -
        1. if arr[num]==arr[left]==arr[right]
        2. whether we are in first half 
            -> if we are in first half, if are going to check whether the target lies in first half on not
            ->if we have to do the same for the second half */
        
        int left =0;
        int right =n-1;
        
        while( left<=right){
            int mid = left+(right-left)/2;
            if( nums[mid]== target) return true;
            
            if( nums[mid]== nums[left] && nums[mid]== nums[right]) {
                left++;
                right--;
            }
            
            //checking the halves
            else if( nums[left]<= nums[mid]){
                //we are in first half right now
                if( target>= nums[left] && target < nums[mid]) right = mid-1;
                else left = mid+1;
            }
            else{
                if( target> nums[mid] && target<= nums[right]) left = mid+1;
                else right = mid-1;
            }
           
        }
        
        return false;
    }
};