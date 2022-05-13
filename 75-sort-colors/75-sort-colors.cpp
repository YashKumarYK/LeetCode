class Solution {
public:
    void sortColors(vector<int>& nums) {
//         int c0=0;
//         int c1=0;
//         int c2=0;
        
//         for(int i=0; i<nums.size(); i++){
//             if( nums[i]==0) c0++;
//             else if( nums[i]==1) c1++;
//             else c2++;
//         }
//         int i=0;
//         while(c0--){
//             nums[i++] = 0;
//         }
//         while(c1--){
//             nums[i++]=1;
//         }
//         while(c2--){
//             nums[i++]=2;
//         }
        
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