class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int maxSum =INT_MIN;
        int currSum =0;
        for( auto i: nums){
            currSum += i;
            maxSum = max(maxSum, currSum);
            if(currSum < 0){
                currSum =0;
            }
        }

        int minSum =INT_MAX;
        currSum = 0;
        for( auto i: nums){
            currSum += i;
            minSum = min(minSum, currSum);
            if(currSum > 0){
                currSum = 0;
            }
        }
        if(maxSum<0) return maxSum;
        return max(totalSum-minSum, maxSum);
    }
};