class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k=0;
        for(int i=0; i<nums.size(); i++){
            nums[k++] = nums[i];
            if( i<n-1&& nums[i]==nums[i+1]){
                nums[k++] = nums[i+1];
                i=i+1;
                while( i<n-1 && nums[i]==nums[i+1]){
                    i++;
                }
             }
        }
        return k;
    }
};