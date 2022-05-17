class Solution {
public:
    void reverse( vector<int> &nums, int s, int e){
        while(s<=e){
            swap(nums[s], nums[e]);
            s++;
            e--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int ind1=-1;
        int ind2;
        int n= nums.size();
        for(int i=n-2;i>=0; i--){
            if( nums[i]< nums[i+1]){
                ind1= i;
                break;
            }   
        }
        
        if(ind1>=0){
            for(int i=n-1; i>=0; i--){
                if(nums[i]> nums[ind1]){
                    ind2= i;
                    break;
                }
            }
            swap(nums[ind1], nums[ind2]);
        }
        reverse( nums, ind1+1, nums.size()-1);
        
        
    }
};