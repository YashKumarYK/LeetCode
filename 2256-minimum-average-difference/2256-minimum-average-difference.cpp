class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        vector<long long> v(nums.size());
        long long sum = 0;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            v[i]= sum;
        }
        
        long long mini = INT_MAX;
        int n=nums.size();
        int ind = -1;
        for(int i=0; i<nums.size(); i++){
            long long left = v[i]/(i+1);
            long long right =0;
            if( i!=n-1)
                right = (sum- v[i])/(n-i-1);
            if( mini >abs( left-right)){
                mini = abs(left- right);
                ind = i;
            }
        }
        return ind;
    }
};