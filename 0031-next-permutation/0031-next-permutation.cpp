class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
        Approach => next permutation is the next element that is just greater than the previous one after re arranginthe element
        1. a decreasing array would never have the next permutation
        2. checking from the last , we found an element breaking the dcreasing order
        3. we need to fing the next just greater element and then make a swap
        4. the part of array that is after the element before swapping needs to reverse to get the next perm.
        */

        int n = nums.size();
        int ind1 =-1;
        for(int i=n-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                ind1=i;
                break;
            }
        }
        int ind2;
        if(ind1 !=-1){
            for(int i=ind1+1;i<n;i++){
                if(nums[i] > nums[ind1]){
                    ind2 = i;
                }
            }
            swap(nums[ind1], nums[ind2]);
        }
        reverse(nums.begin()+ind1+1, nums.end());
    }
};


// 1,2,3,4,7,5,6
// 1,2,3,4,7,6,5