class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Approach2 (optimized approach) - Dutch National Flag Algorithm
        int mid =0;
        int low=0;
        int high = nums.size()-1;
        while( mid<=high){
            switch(nums[mid]){
                case 0: swap(nums[mid++], nums[low++]);
                    break;
                case 1: mid++;
                    break;
                case 2: swap( nums[mid], nums[high--]);
                    break;
            }
        }
    }
};