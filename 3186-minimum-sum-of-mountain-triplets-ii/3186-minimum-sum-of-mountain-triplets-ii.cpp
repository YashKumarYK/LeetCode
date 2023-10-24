class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>  l(n, 0), r(n, 0);
        int m1=nums[0], m2 = nums[n-1];
        for(int i=0;i<n;i++){
            m1 = min(m1, nums[i]);
            l[i] = m1;

            m2 = min(m2, nums[n-i-1]);
            r[n-1-i] = m2;
        }
        int mini = INT_MAX;
        for(int i=1;i<n-1; i++){
            if(nums[i]>l[i-1] && nums[i]>r[i+1]){
                mini = min(mini, nums[i]+l[i-1]+r[i+1]);
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};