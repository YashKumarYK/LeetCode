class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int zero = 0;
        int i=0;
        int j=0;
        int maxLen = 0;
        while(j<n){
            if(nums[j]==0) zero++;
            while(zero>k){
                if(nums[i]==0) zero--;
                i++;
            }
            if(zero<=k){
                maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
        return maxLen;
    }
};