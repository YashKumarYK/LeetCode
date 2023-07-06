class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n = nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int len = INT_MAX;
        while(j<n){
            sum+=nums[j];
            if(t<=sum){
                while(t<=sum){
                    len = min(len, j-i+1);
                    sum-=nums[i];
                    i++;
                }
            }
            j++;
        }
        return len==INT_MAX?0:len;
    }
};