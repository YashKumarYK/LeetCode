class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int s=0;
        int e= s+1;
        
        while(e<nums.size()){
            if( nums[s]== 0 && nums[e]!=0){
                swap(nums[s], nums[e]);
                s++;
                
            }
            if(nums[s]!= 0) s++;
            e++;
        }
    }
};