class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]++;
        int sum = 0;
        int count=0;
        for(auto i: nums){
            sum += i;
            if(mp.count(sum-k)){
                count+= mp[sum-k];
            }
            mp[sum]++;
        }
        return count;
    }
};