class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long, int> mp;
        long long sum =0;
        mp[0] = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mp.find(sum%k)!=mp.end()){
                if(i-mp[sum%k]>0) return true;
            }else{
                mp[sum%k] =  i+1;
            }
        }
        return false;
    }
};