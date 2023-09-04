class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        int i=0;
        int j = 0;
        long long maxSum = 0;
        long long sum =0;
        unordered_map<int,int>mp;
        while(j<n){
            sum += nums[j];
            mp[nums[j]]++;
            if(j-i+1==k){
                if(mp.size()>=m){
                    maxSum = max(maxSum, sum);
                }
            }
            if(j-i+1>k){
                while(j-i+1>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0) mp.erase(nums[i]);
                    sum -= nums[i];
                    i++;
                }

                if(j-i+1==k){
                    if(mp.size()>=m){
                        maxSum = max(maxSum, sum);
                    }
                }
            }
            j++;
        }
        return maxSum;
    }
};