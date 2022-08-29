class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> mp, mp2;
        int maxi =0;
        for( int i=0; i<nums.size(); ++i){
            mp[nums[i]]= i;
            mp2[nums[i]]++;
            maxi = max( maxi, mp2[nums[i]]);
        }
        int len = INT_MAX;
        for( int i=0; i<nums.size(); i++){
            if(maxi ==mp2[nums[i]]){
                len = min( len, mp[nums[i]]- i+1);
                mp2.erase(nums[i]);
           }
        }
        return len;
    }
};