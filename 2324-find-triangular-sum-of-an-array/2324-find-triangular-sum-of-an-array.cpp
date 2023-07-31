class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // base condition:
        if(nums.size()==1) 
            return nums[0];

        //processing
        vector<int> newNums( nums.size()-1);
        for(int j=0;j<nums.size()-1; j++){
            newNums[j]  =( nums[j]+ nums[j+1])%10;
        }

        return triangularSum(newNums);
    }
};

/*

10->20
16=>6
14=>4
num%10;

*/

