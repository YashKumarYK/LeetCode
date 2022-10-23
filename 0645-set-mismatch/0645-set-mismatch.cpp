class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> mp;
        int dup, miss;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])!= mp.end()){
                dup = nums[i];
            }
            mp[nums[i]]++;
        }
        for( int i=1; i<=nums.size(); i++){
            if(mp.find(i)==mp.end()){
                miss=i;
                break;
            }
        }
        return {dup, miss};
    }
};