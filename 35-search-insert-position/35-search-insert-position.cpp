class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e = nums.size()-1;
        int m = s+ (e-s)/2;
        if (nums[e]< target){
            return e+1;
        }
        while( s<e){
            if( target ==nums[m]) return m;
            if( target > nums[m]) s = m+1;
            if( target < nums[m]) e = m;
            m= s+(e-s)/2;
        }
        return e ;
    }
};