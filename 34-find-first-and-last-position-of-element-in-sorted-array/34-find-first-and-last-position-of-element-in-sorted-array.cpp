class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int e= nums.size()-1;
        int s=0;
        int mid = s+ (e-s)/2;
        vector<int> ans;
        int ans1=-1;
        int ans2 = -1;
        
        //for first occurrence
        while( s<=e){
            if( nums[mid] == target){
                ans1= mid;
                e= mid -1;
            }
            else if( nums[mid]> target){
                e = mid-1;
            }
            else{
                s = mid +1;
            }
            mid = s+ (e-s)/2;
        }
        
        e= nums.size()-1;
        s=0;
        mid = s+ (e-s)/2;
        //for the last occurence
        while( s<=e){
            if( nums[mid] == target){
                ans2= mid;
                
                s= mid +1;
            }
            else if( nums[mid]> target){
                e = mid-1;
            }
            else{
                s = mid +1;
            }
            mid = s+ (e-s)/2;
        }
        return {ans1, ans2};
        
    }
};